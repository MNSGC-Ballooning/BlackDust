#include "BlackDust.h"

Pin::Pin(){
}
Pin::Pin(uint8_t spot){
	number = spot;
	state= false;
	prevState= false;
	rising=false;
	falling = false;
	timer =0;
	duration= 0;
	minDuration=0;
	maxDuration=0; 
	pulses = 0;
}
bool Pin::getState(){
	return state;
}
bool Pin::getPrev(){
	return prevState;
}
uint8_t Pin::getPin(){
	return number;
}
void Pin::setState(byte status){   //0 is Low, 1 is High
	prevState = state;
	state = status;
	if(state!=prevState){
		if(state){
			rising = true;
		}
		else{
			falling = true;
		}
	}
}
void Pin::update(){
	if(rising){
		Serial.println("rising!");
		if(millis()-timer>1000){
		pulses++;
		duration = millis()-timer;
		Serial.println(String(duration));
		if(duration>maxDuration){
			maxDuration = duration;
		}
		if(duration<minDuration){
			minDuration = duration;
		}
		}
		rising = false;
		duration = 0;
	}
	if(falling){
		Serial.println("falling");
		timer = millis();
		falling = false;
	}
}
	
		
		
		
dSen::dSen(uint8_t Low, uint8_t High){
	low = Pin(Low);
	high = Pin(High);
}

void dSen::setPins(uint8_t * PINS){
	low = PINS[0];
	high = PINS[1];
}
uint8_t* dSen::getPins(){
	uint8_t gary[2] = {low.getPin(),high.getPin()};
	return gary;
}
void dSen::checkStatus(){
	low.setState(digitalRead(low.getPin()));
	high.setState(digitalRead(high.getPin()));
}
void dSen::update(){
	low.update();
	high.update();
}
uint8_t dSen::getHigh(){
	return high.getPin();
}
uint8_t dSen::getLow(){
	return low.getPin();
}
	
	


