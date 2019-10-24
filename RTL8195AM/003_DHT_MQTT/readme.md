# DHT MQTT demo
This is a project featuring DHT temperature and humidity sensor and MQTT IOT protocol

Temperature and humidity are 2 of the most important factors affecting people’s comfort level in an enclosed space. The DHT humidity and temperature sensor can read the ambient temperature and humidity every 2-3 seconds fastest, and then pass the data to Ameba who will forward them to the server using MQTT protocol. Whoever “subscribing” to the right topic gets the data almost instantaneously. Users can then adjust the aircon mode or temperature according to the readings received.

Of course, this is only one of the applications, or maybe the simplest among everything else. If you are interested to develop even further, you may link the sensor readings to a small program which help you automatically set the aircon to the right setting. Alternatively, you may also put this sensor partially into the soil where plants/vegetables are grown to monitor the soil’s humidity level and decide whether the plant/vegetable should be watered.  

To recreate the projcet successfully, an android phone is to be used as a MQTT client and the Ameba RTL8195 Dev. Board muct act as another MQTT client communicating with the android phone. Both client have to connect to the same MQTT server before proceeding to the next step, you may choose to set up your own MQTT server following an online guide at http://www.steves-internet-guide.com/mqtt-hosting-brokers-and-servers/ or using the free server at https://test.mosquitto.org.

The DHT sensor updates its data every 10 seconds to stay as accurate as possible. Once sensor data is received, Ameba then “publishes” the data to the MQTT server where all clients “subscribing” to the right topic gets the data displayed on the console. 

# Hardware

Ameba 1 RTL8195        x1
DHT sensor(3 pins)     x1
Jumper wires           x3

# Software
1. upload "DHT_MQTT.ino" to your Ameba1 RTL8195 board using arduino IDE
2. Please insatll a MQTT client App on your smart device (android/iOS)
3. Connect to your MQTT server by keying in the correct servre address and topic that you specified in the code
