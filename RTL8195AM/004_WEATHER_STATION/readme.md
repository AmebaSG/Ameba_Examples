# Ameba Weather Station 

If you have watched our previous demo videos, you should have no problem understanding how an LCD display, a DHT Temperature Humidity sensor and our Ameba dev. Board can be put together to form a fully functional smart weather station.  Simply follow the instructions in our examples as follows to DIY your own weather station,
1.	LCD 24H Clock 
2.	MQTT 
3.	DHT+MQTT 
(https://github.com/Realtek-AmebaApp/Ameba_Examples/tree/master/RTL8195AM)
The key to integrate these 3 examples successfully is to make sure that you have set up your MQTT server correctly and note that here we are using a different set of MQTT topics (“dht_data” and “dht_status”). Also, when connect DHT sensor, D13 pin is used as data input pin.

With this smart weather station, you may,
1.	Check real-time temperature and humidity from the LCD display 
2.	Receive warning message when abnormal humidity (>80%) is detected
3.	Query your home/office humidity and temperature on-the-go

Of course, there is always room for creativity.  Imagine your weather station which is safely stationed at home and detects that humidity is higher than 80%, this could be because it is raining, and you forgot to close the window. Now if you happen to have installed a smart windows system, then you may ask Ameba to send a close-all-windows command via MQTT to prevent your room from getting completely wet.

You are also more than welcome to join our online community to meet more makers or raise a question you faced in your own DIY project.

Official pages
https://www.amebaiot.com.cn/en/ 
https://www.amebaiot.com/en/  
Facebook pages
https://www.facebook.com/groups/AmebaIoTWW/  
https://www.facebook.com/groups/AmebaIoT/  
YouTube channel, 
https://www.youtube.com/channel/UCplqTUNYZEoIKs0nAWf9DCQ 
BiliBili channel,
https://space.bilibili.com/457777430 
