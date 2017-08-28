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
	private:
		bool state;
		bool prevState;
		uint8_t number;
		bool rising;
		bool falling;
		unsigned long timer;
		unsigned long duration;
		unsigned long minDuration;
		unsigned long maxDuration;
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
	private:
		Pin low;
		Pin high;
		
};

	
#endif	
