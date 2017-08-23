#include "BlackDust.h"


dSen::dSen(){
	low = 0;
	high = 0;
	lowState = true;
	highState = true;
	prevHigh = true;
	prevLow = true;
	maxDuration = 0;
	minDuration = 0;
	pulseCount = 0;
	changed = false;
	lowTimer = 0;
	highTimer = 0;
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
void dSen::setHighState(byte status){
	prevHigh = highState;
	highState = status;
}
void dSen::setLowState(byte status){
	prevLow = lowState;
	lowState = status;
}
bool dSen::getPrevHigh(){
	return prevHigh;
}
bool dSen::getPrevLow(){
	return prevLow;
}


