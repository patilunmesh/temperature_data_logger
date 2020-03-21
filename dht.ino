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
int val1, val2, val3, val4, val5;
int maxlen = EEPROM.length();
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n"); // if this is printed then all gud
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 if ((addr + 4) < maxlen){
    DHT.read11(dht_apin);
    val1 = DHT.temperature;
        EEPROM.write(addr, val1);
        // Serial.print(val1); // uncomment to see values in runtime
        // Serial.print("\t"); // uncomment to see values in runtime
        addr = addr + 1;
        
    DHT.read11(dht_bpin);
    val2 = DHT.temperature  ;
         EEPROM.write(addr, val2);
         addr = addr + 1;
        // Serial.print(val2); // uncomment to see values in runtime
        // Serial.print("\t"); // uncomment to see values in runtime
    DHT.read11(dht_cpin);
    val3 = DHT.temperature ;
         EEPROM.write(addr, val3);
        // Serial.print(val3); // uncomment to see values in runtime
         // Serial.print("\t"); // uncomment to see values in runtime
         addr = addr + 1;
    DHT.read11(dht_dpin);
    val4 = DHT.temperature  ;
        EEPROM.write(addr, val4);
       // Serial.print(val4); // uncomment to see values in runtime
        // Serial.print("\t");  // uncomment to see values in runtime
        addr = addr + 1;
    DHT.read11(dht_epin);
    val5 = DHT.temperature  ;
         EEPROM.write(addr, val5);
        // Serial.print(val5);  // uncomment to see values in runtime
         // Serial.print("\t");  // uncomment to see values in runtime
         addr = addr + 1;
 }

 // Serial.println("recorded\n");
 //   Serial.print("\n");
  if (addr >= (maxlen - 4)) {
    addr = 0;}
    delay(600000); //Wait 10 minutes before accessing sensor again. for any other time 60000*minutes can be added here
 
 
}// end loop()
