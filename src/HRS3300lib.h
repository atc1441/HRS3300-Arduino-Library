#ifndef BSEC_CLASS_H
#define BSEC_CLASS_H

#include "Arduino.h"
#include "hrs3300.h"


class HRS3300lib
{
public:

	HRS3300lib();

	void begin(void);
	
	void end(void);
	
	uint8_t getHR(void);

};

#endif
