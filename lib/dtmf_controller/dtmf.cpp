#include "dtmf.h"
#include <Arduino.h>

DTMFController::DTMFController(int pin1, int pin2, int pin3, int pin4, int data, int input)
{
    _pin1 = pin1;
    _pin2 = pin2;
    _pin3 = pin3;
    _pin4 = pin4;
    _data = data;
    _input = input;

    pinMode(_pin1, INPUT_PULLDOWN);
    pinMode(_pin2, INPUT_PULLDOWN);
    pinMode(_pin3, INPUT_PULLDOWN);
    pinMode(_pin4, INPUT_PULLDOWN);
    pinMode(_data, INPUT_PULLDOWN);
    pinMode(_input, OUTPUT);

    digitalWrite(_input, LOW);
    _inputState = 0;
    _prevByte = -1; // -1 because it's not in the DTMF code
    _newData = 0;
    _prevData = 0;

    _recSequence = 0;
    _compSequence = 0;
    _sequence = {};
}

int DTMFController::update()
{
    int currByte = DTMFController::read();
    int dataOn = digitalRead(_data);

    if (dataOn && (_prevData == 0 || _prevByte != currByte))
    {
        _newData = 1;
    }
    else
    {
        _newData = 0;
    }

    _prevData = dataOn;
    _prevByte = currByte;

    // Serial.printf("dataOn: %i; newData: %i; prevData: %i; currByte: %i; prevByte: %i\n", dataOn, _newData, _prevData, currByte, _prevByte);

    if (_newData == 1)
    {
        switch (currByte)
        {
        case static_cast<int>(DTMFCode::ASTERISK):
            _recSequence = 1;
            break;
        case static_cast<int>(DTMFCode::POUND):
            _recSequence = 0;
            break;
        case static_cast<int>(DTMFCode::A): // Other functionality could be added here in the future.
            break;
        case static_cast<int>(DTMFCode::B):
            break;
        case static_cast<int>(DTMFCode::C):
            break;
        case static_cast<int>(DTMFCode::D):
            break;
        default:
            if (_recSequence == 1)
            {
                _sequence.push_back(currByte);
            }
        }
    }
    return _newData;
}

void DTMFController::enableInput()
{
    digitalWrite(_input, LOW);
    _inputState = 1;
}

void DTMFController::disableInput()
{
    digitalWrite(_input, HIGH);
    _inputState = 0;
}

// std::vector<int> DTMFController::readAll(){
//     std::vector<int> bus;

//     bus.push_back(digitalRead(_pin1));
//     bus.push_back(digitalRead(_pin2));
//     bus.push_back(digitalRead(_pin3));
//     bus.push_back(digitalRead(_pin4));

//     return bus;
// }

int DTMFController::read()
{
    int q1 = digitalRead(_pin1);
    int q2 = digitalRead(_pin2);
    int q3 = digitalRead(_pin3);
    int q4 = digitalRead(_pin4);

    int byte = 1 * q1 + 2 * q2 + 4 * q3 + 8 * q4;

    if (byte == 10)
    {
        byte = 0; // Device uses "10" to represent dtmf code of "0"
    }
    else if (byte == 0)
    {
        byte = 10; // Device uses "0" for a dtmf code of "D"
    }

    return byte;
}

std::vector<int> DTMFController::readSequence(){
    std::vector<int> sequence = _sequence;
    if(_recSequence == 0){
        _sequence = {};
        return sequence;
    } else {
        return {};
    }
}