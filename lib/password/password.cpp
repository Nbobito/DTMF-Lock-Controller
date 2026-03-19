#include "password.h"

bool checkPassword(const std::vector<int>& attempt, int password){
    int digits = 0;
    for(int d : attempt) digits = digits * 10 + d;

    return digits == password;
}