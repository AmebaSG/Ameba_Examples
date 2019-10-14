/*
 Basic MQTT example

 This sketch demonstrates the basic capabilities of the library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary

 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.
 
*/

#include <WiFi.h>
#include <PubSubClient.h>


// constants won't change. They're used here to set pin numbers:
const int buttonPin = 0;     // the number of the pushbutton pin
const int ledPin =  1;      // the number of the LED pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int ledState = 0;



// Update these with values suitable for your network.

char ssid[] = "your wifi ssid";     // your network SSID (name)
char pass[] = "your wifi password";  // your network password
int status  = WL_IDLE_STATUS;    // the Wifi radio's status

char mqttServer[]     = "your mqtt server public ip address";//if unavailable, use "mqtt.eclipse.org" instead. beware that this is a free mqtt server thus unstablity is expected sometimes
char clientId[]       = "amebaClient";
char publishTopic[]   = "outTopic";
char publishPayload_1[] = "LED is ON";
char publishPayload_2[] = "LED is OFF";
char subscribeTopic[] = "inTopic";
int callbackvalue=0;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) 
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  callbackvalue = (int)payload[0];
  Serial.println(callbackvalue);
}

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
      client.publish(publishTopic, publishPayload_2);
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

void setup()
{
  Serial.begin(38400);

   // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  client.setServer(mqttServer, 1883);
  client.setCallback(callback);

  // Allow the hardware to sort itself out
  delay(1500);
}


    
void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH)
  {
    if(ledState == HIGH){
      client.publish(publishTopic, publishPayload_1);
    }
    else{
      client.publish(publishTopic, publishPayload_2);
    }
    
    Serial.println("button pressed");
    delay(200);
  }


  if(callbackvalue == 49) //49 is equivalent to 1 on ASCII table
  {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    ledState = HIGH;
    //Serial.print("callbackvalue received:");
    //Serial.println(callbackvalue);
  }
  else
  {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    ledState = LOW;
    //Serial.print("callbackvalue received");
  }
  
  client.loop();
}
