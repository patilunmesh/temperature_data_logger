#include "dht.h"
#define dht_apin A0
#define dht_bpin A1
#define dht_cpin A2
#define dht_dpin A3
#define dht_epin A4

// Analog Pin sensor is connected to
#include <EEPROM.h>

dht DHT;
int addr = 0; 
int val1, val2, val3, val4, val5;
int maxlen = EEPROM.length();
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 if ((addr + 4) < maxlen){
    DHT.read11(dht_apin);
    val1 = DHT.temperature;
        EEPROM.write(addr, val1);
        addr = addr + 1;
        
    DHT.read11(dht_bpin);
    val2 = DHT.temperature - val1 ;
         EEPROM.write(addr, val2);
         addr = addr + 1;
    DHT.read11(dht_cpin);
    val3 = DHT.temperature - val1 ;
         EEPROM.write(addr, val3);
         addr = addr + 1;
    DHT.read11(dht_dpin);
    val4 = DHT.temperature - val1 ;
        EEPROM.write(addr, val4);
        addr = addr + 1;
    DHT.read11(dht_epin);
    val5 = DHT.temperature - val1 ;
         EEPROM.write(addr, val5);
         addr = addr + 1;
 }
   
  if (addr == maxlen) {
    addr = 0;}
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
 
}// end loop()
