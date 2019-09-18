#include <Wire.h>
#include <RTL8710AF_LiquidCrystal_I2C.h>
RTL8710AF_LiquidCrystal_I2C lcd(0x27, 16, 2);

int hour = 15;
int minute = 50;
int second = 40; 
int error = 1;

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.print("Please wait...");  
  Serial.begin(9600);
  Serial.println("LCD Clock 24h");
}

void loop()
{
  delay(1000);
  time_count();
  if (error == 0)
  {
    lcd.clear();
    lcd.print("LCD Clock 24h");
    lcd.setCursor(0, 1);
    lcd.print(hour);
    lcd.print(" : ");
    lcd.print(minute);
    lcd.print(" : ");
    lcd.print(second);
  }
}

void time_count()
{ 
  if (hour < 0 || hour > 24)
  {
    lcd.clear();
    lcd.print("Hour Err!!!");
  }
  else if (minute < 0 || minute > 60)
  {
    lcd.clear();
    lcd.print("Min Err!!!");
  }
  else if (second < 0 || second > 60)
  {
    lcd.clear();
    lcd.print("Sec Err!!!");
  }
  else
  {
    error = 0;
    second++;
    if (second == 60)
    {
      minute++;
      second = 0;
    }
    if (minute == 60)
    {
      hour++;
      minute = 0;
    }
    if (hour == 24)
    {
      hour = 0;
    }
  }
}
