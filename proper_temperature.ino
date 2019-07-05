#include <DS18B20.h>

#define ledPin 13
#define serialBaudRate 9600
#define properTemperature 28

DS18B20 ds(2);

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(serialBaudRate);
}

void loop() {
  while (ds.selectNext()) {
    if(ds.getTempC() > properTemperature){
      digitalWrite(ledPin,HIGH);
    }
    else{
      digitalWrite(ledPin,LOW);
    }
    //Serial.println(ds.getTempC());
  }
}
