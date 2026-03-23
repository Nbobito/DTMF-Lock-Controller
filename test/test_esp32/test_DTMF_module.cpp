#include <Arduino.h>
#include "dtmf.h"
#include "configs.h"

DTMFController DTMF(Pins::DTMF::Q1, Pins::DTMF::Q2, Pins::DTMF::Q3, Pins::DTMF::Q4, Pins::DTMF::StQ, Pins::DTMF::in);
std::vector<int> bus;
int disableCounter = 0;

void setup()
{
    Serial.begin(115200);
    Serial.println("Serial connection started at 9600 baud");
    DTMF.enableInput();
}

void loop()
{
    if(DTMF.update() == 1){ // Fix this triggering twice / three times?
        int byte = DTMF.read();

        Serial.print("Read byte: ");
        Serial.println(byte);
        delay(10);
    }

    std::vector<int> sequence = DTMF.readSequence();

    if(!sequence.empty()){
        Serial.print("Read sequence: ");
        for (int d : sequence){
            Serial.print(d);
            Serial.print(" ");
        }
        Serial.println();
        delay(10);
    }
}
