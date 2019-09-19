# LCD 24H Clock
The example featuring Realtek Ameba RTL8195. The Ameba board is pre-programmed with code written on Arduino IDE and connects to the LCD screen via I2C protocol.

The 24H clock is capable of displaying hour, minute and second on the LCD screen and counting up to 24 hours. It will reset itself after time has passed longer than 24 hours.


# Software coding
The codes only uploads to RTL8195 by Arduino IDE

Please refer to LCD_clock.ino

# Hardware connections
LCD screen is LCD 1602 with I2C

Please refer to Hardware connection.png

# RTL8710AF_LiquidCrystal_I2C-library-master.zip 
This is a ZIP library for i2C LCD screen. The ZIP library must be installed before using the LCD. Please refer to the following steps for install the library. 
Open the LCD_clock.ino, go to " sketch/Include Library/Add .ZIP Library " and chose "RTL8710AF_LiquidCrystal_I2C-library-master.zip "
