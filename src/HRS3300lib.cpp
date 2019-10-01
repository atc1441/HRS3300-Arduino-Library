#include "HRS3300lib.h"
#include <Wire.h>

extern "C" { int __hardfp_sqrt(int f){ return sqrt(f); } }


HRS3300lib::HRS3300lib()
{

}

void HRS3300lib::begin(void)
{
  Wire.begin();
  Hrs3300_chip_init();
  Hrs3300_chip_enable();
  Hrs3300_set_exinf(0, 0, 0, 0, 0, 0);
  Hrs3300_alg_open();
}

void HRS3300lib::end(void)
{
  Hrs3300_chip_disable();
}

uint8_t HRS3300lib::getHR(void)
{
  return get_heart_rate();
}

void Hrs3300_write_reg(uint8_t addr, uint8_t data) 
{
  Wire.beginTransmission(0x44);
  Wire.write(addr);
  Wire.write(data);
  Wire.endTransmission();
}

uint8_t Hrs3300_read_reg(uint8_t addr) 
{
  Wire.beginTransmission(0x44);
  Wire.write(addr);
  Wire.endTransmission();
  Wire.requestFrom(0x44, 1);
  return Wire.read();
}

