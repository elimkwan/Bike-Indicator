#include <IRremote.h>
//https://www.circuitbasics.com/arduino-ir-remote-receiver-tutorial/
//https://github.com/Arduino-IRremote/Arduino-IRremote/blob/master/README.md

const int IR_RECEIVE_PIN = 12;

void setup(){
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
}

void loop(){
  if (IrReceiver.decode()) {
      uint32_t data = IrReceiver.decodedIRData.decodedRawData;
      if (data != 0){
        Serial.println(data, HEX); 
      }
      IrReceiver.resume(); // Enable receiving of the next value
  }
}
