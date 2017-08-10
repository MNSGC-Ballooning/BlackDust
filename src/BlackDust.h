#ifndef BlackDust_h
#define BlackDust_h

#include <arduino.h>

class dSen{
	public:
		dSen();
		dSen(uint8_t Low , uint8_t High );
		void setPins(uint8_t * PINS);
		uint8_t* getPins();
	private:
		uint8_t low;
		uint8_t high;
};
#endif	
