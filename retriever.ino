#include <EEPROM.h>

int a = 0;
int value0;
int value;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print(a);
  Serial.print("\t");
  value0 = EEPROM.read(a);
  Serial.print(value0);
  for (int i = 1 ; i < 5 ; i++)
    {
      if((a + i) >= EEPROM.length()) {
        Serial.print("memory limit exceeded while reading, clearing memory");
        delay(2000);
    for (int i = 0 ; i < EEPROM.length() ; i++)
    {
    EEPROM.write(i, 0);
    }
    Serial.print("cleared memory");
        }
  if((a + i) < EEPROM.length()) {
  value = value0 + EEPROM.read(a + i);
  Serial.print("\t");
  Serial.print(value);
    }
    }
  Serial.println();
  if (value == 255 ){
    Serial.print("reached limit so abort, clearing the memory");
    delay(2000);
    for (int i = 0 ; i < EEPROM.length() ; i++)
    {
    EEPROM.write(i, 0);
    }
    Serial.print("cleared memory");
  }
  
  a = a + 1;

  if (a == EEPROM.length()){
    Serial.print("memory limit exceeded, clearing memory");
    delay(2000);
    for (int i = 0 ; i < EEPROM.length() ; i++)
    {
    EEPROM.write(i, 0);
    }
    Serial.print("cleared memory");
    a = 0;
  }

  delay(500);
}
