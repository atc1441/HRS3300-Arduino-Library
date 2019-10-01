/*
    This Library is made for the HRS3300 Heartrate Sensor
	
	you need to edit the platform.txt of your nRF52 library as in library.properties writen.
	
    this is an easy example.
	
    The getHR has to be called quite accurate otherwise it will give wrong results.

    to disable the Sensor call HRS3300.end(); and pull the HRSpowerPin HIGH.
*/

#include "HRS3300lib.h"

#define HRSPowerPin 26

HRS3300lib HRS3300;

int refreshTime;

void setup(void)
{
  delay(1000);
  Serial.begin(115200);
  Serial.println("HRS3300 HRS sensor test");
  pinMode(HRSPowerPin, OUTPUT);
  digitalWrite(HRSPowerPin, LOW);
  HRS3300.begin();
}

void loop() {
  if (millis() - refreshTime > 20) {
    refreshTime = millis();
    uint8_t algo = HRS3300.getHR();
    switch (algo) {
      case 255:
        // nothing hrs data gets only every 25 calls answered
        break;
      case 254:
        Serial.println("NO_TOUCH"); // Sensor not touched put finger or wrist on it
        break;
      case 253:
        Serial.println("DATA_TOO_SHORT"); // Not enough data to calculate Heartrate please wait
        break;
      default:
        Serial.println(algo);
        break;
    }
  }
}