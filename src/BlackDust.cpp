#include "BlackDust.h"

Pin::Pin(){
}
Pin::Pin(uint8_t spot){
	number = spot;
	state= false;
	prevState= false;
	rising=false;
	falling = false;
	first = true;
	timer =0;
	duration= 0;
	minDuration=100000;
	maxDuration=0; 
	pulses = 0;
	LPO = 0;
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
	if(rising&&!first){
		Serial.println("rising");
		pulses++;
		duration = millis()-timer;
		LPO+=duration;
		Serial.println(String(duration));
		if(duration>maxDuration){
			maxDuration = duration;
		}
		if(duration<minDuration){
			minDuration = duration;
		}
		rising = false;
		duration = 0;
	}
	if(falling){
		Serial.println("falling");
		falling = false;
		timer = millis();
		first = false;
	}
	if(rising&&first){
		Serial.println("checking first rise");
		first = false;
		rising = false;
	}
}
String Pin::reset(){
	String toPrint = "";
	toPrint += String(pulses);
	toPrint += ",";
	toPrint += String(LPO/float(30000));      //counting on a 30 second sample time
	toPrint += ",";
	if(pulses!=0){
		toPrint += String(LPO/pulses);     //average pulse length
	}
	else{
		toPrint+= "0";
	}
	toPrint += ",";
	if(minDuration == 100000){
		toPrint+= "0";
	}
	else{
		toPrint += String(minDuration);
	}
	toPrint += ",";
	toPrint += String(maxDuration);
	timer =millis();
	duration= 0;
	minDuration=100000;
	maxDuration=0; 
	pulses = 0;
	LPO = 0;
	first = true;
	return toPrint;
	
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
String dSen::reset(uint8_t sensor){
	String toSend = String(sensor) + ",low,";
	toSend +=low.reset();
	toSend += "\n" +String(sensor) + ",high,";
	toSend +=high.reset();
	return toSend;
}

	
	


