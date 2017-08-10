#include "BlackDust.h"


dSen::dSen(){
	low = 0;
	high = 0;
}
dSen::dSen(uint8_t LOW, uint8_t HIGH){
	low = LOW;
	high = HIGH;
}

void dSen::setPins(uint8_t * PINS){
	low = PINS[0];
	high = PINS[1];
}
uint8_t* dSen::getPins(){
	uint8_t gary[2] = {low,high};
	return gary;
}
