#include "BlackDust.h"


dSen::dSen(){
	low = 0;
	high = 0;
}
dSen::dSen(uint8_t Low, uint8_t High){
	low = Low;
	high = High;
}

void dSen::setPins(uint8_t * PINS){
	low = PINS[0];
	high = PINS[1];
}
uint8_t* dSen::getPins(){
	uint8_t gary[2] = {low,high};
	return gary;
}
uint8_t dSen::getLow(){
	return low;
}
uint8_t dSen::getHigh(){
	return high;
}
bool dSen::getHighState(){
	return highState;
}
bool dSen::getLowState(){
	return lowState;
}
//void dSen::setHighState(byte status

