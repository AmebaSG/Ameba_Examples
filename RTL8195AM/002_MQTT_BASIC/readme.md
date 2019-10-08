# MQTT Demo with Ameba RTL8195

This example is a variation to the original “mqtt basic” example that comes with the Arduino package. In this example, simple passive components are used to aid in demonstrating the power of bidirectional communication of MQTT protocol which is widely used in modern IOT applications for its advantages in speedy response and lightweight.

In this demo, an android tablet was used as a MQTT client and our Ameba RTL8195 Dev. Board acted as another MQTT client communicating with the android tablet. Both client have to connect to the same MQTT server before proceeding to the next step, you may choose to set up your own MQTT server following an online guide like this or using the free server at https://test.mosquitto.org.

By sending a “1” from the android device to the Ameba board, it turns on the LED connected with Ameba, a “0” would turn off the LED. At any time, you may press the push button connected with the Ameba board to enquire the LED status and forward it back to the android tablet. This setup simulates the real application of IOT product available in our household and is very easy to implement. If you are interested in doing it yourself, please refer to our GitHub page for further details.

# Software 
1. upload "MQTT_BASIC.ino" to your Ameba RTL8195 board using arduino IDE
2. Please insatll a MQTT client App on your smart device (android/iOS)

# Hardware
Item list:
1. LED                x1
2. Push button        x1
3. Breadboard         x1
4. wires              x4
5. 220ohm resistor    x2
6. Android/iOS device x1
7. Stand (optional)   x1
