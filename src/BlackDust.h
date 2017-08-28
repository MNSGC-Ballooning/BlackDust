#ifndef BlackDust_h
#define BlackDust_h

#include <arduino.h>
class Pin{
	public:
		Pin();
		Pin(uint8_t spot);
		bool getState();
		bool getPrev();
		uint8_t getPin();
		void setState(byte status);
		void update();
		String reset();
	private:
		bool first;
		byte state;
		byte prevState;
		uint8_t number;
		bool rising;
		bool falling;
		unsigned long timer;
		unsigned long duration;
		unsigned long minDuration;
		unsigned long maxDuration;
		unsigned long LPO;
		uint8_t pulses;
		
};
class dSen{
	public:
		dSen(uint8_t Low , uint8_t High );
		void setPins(uint8_t * PINS);
		uint8_t* getPins();
		bool changed;
		void update();
		void checkStatus();
		uint8_t getLow();
		uint8_t getHigh();
		String  reset();
	private:
		Pin low;
		Pin high;
		
};

	
#endif	
