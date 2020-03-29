#include "dht.h"
#define dht_apin A0
#define dht_bpin A1
#define dht_cpin A2
#define dht_dpin A3
#define dht_epin A4
// Analog Pin sensor is connected to A0, A1, A2, A3, A4
#include <EEPROM.h>
dht DHT;
int addr = 0; 
int val10, val11 ;
int maxlen = EEPROM.length();
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n"); // if this is printed then all gud
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
 if ((addr + 8) < maxlen){
    DHT.read11(dht_apin);
        EEPROM.write(addr, DHT.temperature);
        addr = addr + 1;
        EEPROM.write(addr, DHT.humidity);
        addr = addr + 1;
        
    DHT.read11(dht_bpin);
        EEPROM.write(addr, DHT.temperature);
        addr = addr + 1;
        EEPROM.write(addr, DHT.humidity);
        addr = addr + 1;
        
    DHT.read11(dht_cpin);
        EEPROM.write(addr, DHT.temperature);
        addr = addr + 1;
        EEPROM.write(addr, DHT.humidity);
        addr = addr + 1;
        
    DHT.read11(dht_dpin);
        EEPROM.write(addr, DHT.temperature);
        addr = addr + 1;
        EEPROM.write(addr, DHT.humidity);
        addr = addr + 1;
        
    DHT.read11(dht_epin);
        EEPROM.write(addr, DHT.temperature);
        addr = addr + 1;
        EEPROM.write(addr, DHT.humidity);
        addr = addr + 1;
 }
  if (addr >= (maxlen - 4)) {
    addr = 0;}
    delay(600000); //Wait 10 minutes before accessing sensor again. for any other time 60000*minutes can be added here 
}
