#include "dtmf.h"
#include <Arduino.h>

DTMFController::DTMFController(int pin1, int pin2, int pin3, int pin4, int data, int input){
    _pin1 = pin1;
    _pin2 = pin2;
    _pin3 = pin3;
    _pin4 = pin4;
    _data = data;
    _input = input;

    pinMode(_pin1, INPUT);
    pinMode(_pin2, INPUT);
    pinMode(_pin3, INPUT);
    pinMode(_pin4, INPUT);
    pinMode(_data, INPUT);
    pinMode(_input, OUTPUT);
}

void DTMFController::enableInput(){
    digitalWrite(_input, HIGH);
}

void DTMFController::disableInput(){
    digitalWrite(_input, LOW);
}