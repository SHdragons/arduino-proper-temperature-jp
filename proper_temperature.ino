#include <DS18B20.h>

#define ledPin 13 //LEDを光らせるピン番号の設定
#define serialBaudRate 9600 //シリアル通信のボーレートの設定
#define properTemperature 28 //適温の設定(℃)

DS18B20 ds(2); //温度センサの入力PINの指定（ここでは2番ピン）

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(serialBaudRate);
}

void loop() {
  while (ds.selectNext()) {
    if(ds.getTempC() > properTemperature){
      digitalWrite(ledPin,HIGH);  //適温より高ければLED点灯
    }
    else{
      digitalWrite(ledPin,LOW);  //適温以下ならLED消灯
    }
    //Serial.println(ds.getTempC());  //シリアル通信でテスト表示用
  }
}
