#include <EEPROM.h>
int a = 0;
int value0;
int value;
int k = -1;
void setup()
{ Serial.begin(9600); }
void loop()
{
  Serial.print(a);
  Serial.print("\t");
 while(a < EEPROM.length()) {
      Serial.print(EEPROM.read(a));
      Serial.print("\t");
      a++;
      Serial.print(EEPROM.read(a));
      Serial.print("\t\t");
      if(a == k + 10){
        Serial.println();
        k = a; }
      a++;    }
  if(a >= EEPROM.length()) {
        Serial.print("memory limit exceeded while reading, clearing memory");
        delay(2000);
    for (int i = 0 ; i < EEPROM.length() ; i++)
    {
    EEPROM.write(i, 0);
    }
    Serial.print("cleared memory");  }
 delay(10);
}
