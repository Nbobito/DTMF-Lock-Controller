#include <Arduino.h>
#include "solenoid.h"

Solenoid::Solenoid(int pin){
    _pin = pin;
    _toggleTime = millis();
    _state = 0;

    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

int Solenoid::toggleTime(){
    int deltaTime = millis() - _toggleTime;
    return deltaTime;
}

int Solenoid::state(){
    return _state;
}

void Solenoid::extend(){
    digitalWrite(_pin, HIGH);

    if(_state == 0){
        _toggleTime = millis();
    }

    _state = 1;
}

void Solenoid::retract(){
    digitalWrite(_pin, LOW);

    if(_state == 1){
        _toggleTime = millis();
    }

    _state = 0;
}

void Solenoid::toggle(){
    if(_state == 0){
        digitalWrite(_pin, HIGH);
        _state = 1;
    } else {
        digitalWrite(_pin, LOW);
        _state = 0;
    }

    _toggleTime = millis();
}