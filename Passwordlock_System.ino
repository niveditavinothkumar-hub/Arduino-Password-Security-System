#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

String password = "1234";
String input = "";

int led = 8;
int attempts = 0;

void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(led, OUTPUT);

  Serial.begin(9600);

  lcd.print("Enter Password");
}

void loop()
{
  if(Serial.available())
  {
    input = Serial.readString();
    input.trim();

    lcd.clear();

    if(input == password)
    {
      lcd.print("Access Granted");

      digitalWrite(led, HIGH);
      delay(2000);
      digitalWrite(led, LOW);

      attempts = 0; // reset attempts
    }
    else
    {
      attempts++;

      lcd.print("Access Denied");

      for(int i=0;i<3;i++)
      {
        digitalWrite(led,HIGH);
        delay(300);
        digitalWrite(led,LOW);
        delay(300);
      }

      if(attempts >= 3)
      {
        lcd.clear();
        lcd.print("SYSTEM LOCKED");

        for(int i=0;i<10;i++)
        {
          digitalWrite(led,HIGH);
          delay(200);
          digitalWrite(led,LOW);
          delay(200);
        }

        delay(10000); // wait 10 sec

        attempts = 0;
        lcd.clear();
        lcd.print("Try Again");
      }
    }

    delay(2000);

    lcd.clear();
    lcd.print("Enter Password");
  }
}