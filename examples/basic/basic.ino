/*
    This Library is made for the HRS3300 Heartrate Sensor
	
	you need to edit the platform.txt of your nRF52 library as in library.properties writen.
	
    this is an easy example.
	
    The getHR has to be called quite accurate otherwise it will give wrong results.

    to disable the Sensor call HRS3300_disable(); and pull the HRSpowerPin HIGH.
*/

#include <Wire.h>
#include "HRS3300lib.h"

#define HRSPowerPin 26

int refreshTime;

void setup(void)
{
  delay(1000);
  Wire.begin();
  Serial.begin(115200);
  Serial.println("HRS3300 HRS sensor test");
  pinMode(HRSPowerPin, OUTPUT);
  digitalWrite(HRSPowerPin, LOW);
  HRS3300_begin(user_i2c_read, user_i2c_write);
}

void loop() {
  if (millis() - refreshTime > 40) {
    refreshTime = millis();
    uint8_t algo = HRS3300_getHR();
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
        Serial.println(algo); //Got a heartrate print it to Serial
        break;
    }
  }
}

uint8_t user_i2c_read(uint8_t addr, uint8_t reg_addr, uint8_t *reg_data, uint32_t length)
{
  Wire.beginTransmission(addr);
  Wire.write(reg_addr);
  if ( Wire.endTransmission())return -1;
  Wire.requestFrom(addr, length);
  for (int i = 0; i < length; i++) {
    *reg_data++ = Wire.read();
  }
  return 0;
}

uint8_t user_i2c_write(uint8_t addr, uint8_t reg_addr, const uint8_t *reg_data, uint32_t length)
{
  byte error;
  Wire.beginTransmission(addr);
  Wire.write(reg_addr);
  for (int i = 0; i < length; i++) {
    Wire.write(*reg_data++);
  }
  if ( Wire.endTransmission())return -1;
  return 0;
}