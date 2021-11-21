#include <SevSeg.h>
#include <IRremote.h>
// https://www.circuitbasics.com/arduino-7-segment-display-tutorial/
SevSeg sevseg;
const int IR_RECEIVE_PIN = 12;

void setup(){
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
  bool resistorsOnSegments = true;
  
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
}

void loop(){
  if (IrReceiver.decode()) {
      uint32_t data = IrReceiver.decodedIRData.decodedRawData;
      if (data == 0xF30CFF00){ //Button 1
        sevseg.setChars("1");
      } else if (data == 0xA15EFF00) { //Button 3
        sevseg.setChars("r");
      }
      sevseg.refreshDisplay();
      IrReceiver.resume(); // Enable receiving of the next value
  }       
}
