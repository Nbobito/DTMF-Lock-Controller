#pragma once

#include<vector>

enum class DTMFCode : int { // These codes swap Zero and D for simplicity
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    ASTERISK = 11,
    POUND = 12,
    A = 13,
    B = 14,
    C = 15, 
    D = 10

};

class DTMFController {
    public:

    DTMFController(int pin1, int pin2, int pin3, int pin4, int data, int input);
    
    int update();
    void disableInput();
    void enableInput();
    int read();
    std::vector<int> readSequence();

    private:

    int _pin1;
    int _pin2;
    int _pin3;
    int _pin4;
    int _data;
    int _input;

    int _inputState;
    int _prevByte;
    int _newData;
    int _prevData;

    int _recSequence;
    int _compSequence;
    std::vector<int> _sequence;
};