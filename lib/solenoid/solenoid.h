#pragma once

class Solenoid {
    public:
        Solenoid(int pin);

        int toggleTime();
        int state();

        void extend();
        void retract();
        void toggle();
    
    private:
        int _pin;
        int _toggleTime;
        int _state;
};