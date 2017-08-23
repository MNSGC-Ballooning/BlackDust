#ifndef BlackDust_h
#define BlackDust_h

#include <arduino.h>

class dSen{
	public:
		dSen();
		dSen(uint8_t Low , uint8_t High );
		void setPins(uint8_t * PINS);
		uint8_t* getPins();
		uint8_t getLow();
		uint8_t getHigh();
		bool getHighState();
		bool getLowState();
		bool getPrevHigh();
		bool getPrevLow();
		void setHighState(byte status);
		void setLowState(byte status);
		bool changed;
		unsigned long lowTimer;
		unsigned long highTimer;
	private:
		uint8_t low;
		uint8_t high;
		bool prevLow;
		bool prevHigh;
		bool lowState;
		bool highState;
		unsigned long maxDuration;
		unsigned long minDuration;
		uint8_t pulseCount;
		
};
class Pin{
	public:
		Pin(uint8_t spot);
		bool getState();
		bool getPrev();
		uint8_t getPin();
		void setState(byte status);
	private:
		uint8_t number;
		bool changed;
	
#endif	
