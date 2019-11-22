#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"
#include <avr/dtostrf.h>
#include <Wire.h>
#include <RTL8710AF_LiquidCrystal_I2C.h>

#define DHTPIN 13     // what digital pin we're connected to
#define HUMIDITY_THRESHOLD 80 //Threshold to trigger an alert

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)


char ssid[] = "xxxxxxxxxxxx"; // your network SSID (name)
char pass[] = "xxxxxxxxxxxx";     // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;


char mqttServer[]     = "xxxxxxxxxxxxxxx"; // replace and key in the IP address of your mqtt server, if unavailable, type "test.mosquitto.org" instead, but beware that this is a free test server, unstability is expected
char clientId[]       = "amebaClient_xxx"; // you may replace the xxx with your name initials to avoid same clientID collision
char publishTopic[]   = "dht_data";
char publishPayload[] = "Ameba online!";
char publishwarning[] = "Humidity threshold reached!";
char subscribeTopic[] = "dht_status";
int callbackPayload = 0;


DHT dht(DHTPIN, DHTTYPE);
RTL8710AF_LiquidCrystal_I2C lcd(0x27, 16, 2);

WiFiClient wifiClient;
PubSubClient client(wifiClient);


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientId)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish(publishTopic, publishPayload);
      // ... and resubscribe
      client.subscribe(subscribeTopic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) 
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  callbackPayload = (int)payload[0];
  Serial.println(callbackPayload);
}

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.print("Please wait...");
  
  Serial.begin(38400);
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    lcd.clear();
    lcd.print("Wifi Connecting");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(5000);
  }
  Serial.println("Connected to wifi");
  lcd.clear();
  lcd.print("Wifi Connected!");
  Serial.println("DHTxx test!");
  dht.begin();

  client.setServer(mqttServer, 1883);
  client.setCallback(callback);
  client.subscribe(subscribeTopic);
  // Allow the hardware to sort itself out
  delay(1500);
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  //wait 5seconds between measurements 
  delay(5000);
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.print("Error! ");
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  lcd.clear();
  lcd.print("Humd: ");
  lcd.print(h);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
    
  if(h>=HUMIDITY_THRESHOLD)
  {
    //Send a warning msf thu mqtt here
    client.publish(publishTopic, publishwarning);
    lcd.clear();
    lcd.print("Warning sent!");
  }

  if(callbackPayload == 63) {//63 is equivalent to "?" on ASCII table
    static char humidity[10];
    static char temperature[10];
    dtostrf(h, 5, 3, humidity);
    dtostrf(t, 5, 3, temperature);
    static char buffer[128];
    snprintf(buffer, 20, "%s,%s", humidity, temperature);
    Serial.println(buffer);
    client.publish(publishTopic, buffer);
    callbackPayload = 0;
  }
  client.loop();
}//end of loop
