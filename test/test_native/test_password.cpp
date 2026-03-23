#include<iostream>
#include<unity.h>
#include<vector>
#include<algorithm>

#include "password.h"
#include "configs.h"

std::vector<int> convertToVector(int password){
    std::vector<int> digits;

    while(password != 0){
        digits.push_back(password % 10);
        password = password / 10;
    }

    std::reverse(digits.begin(), digits.end());

    return digits;
}

void testTrueCases(){
    std::vector<int> digitsTrue = convertToVector(Config::password);
    TEST_ASSERT_TRUE(checkPassword(digitsTrue, Config::password));

    int testPassword = 124560;
    std::vector<int> testAttempt = {1, 2, 4, 5, 6, 0};
    TEST_ASSERT_TRUE(checkPassword(testAttempt, testPassword));

    testPassword = 100200300;
    testAttempt = {1, 0, 0, 2, 0, 0, 3, 0, 0};
    TEST_ASSERT_TRUE(checkPassword(testAttempt, testPassword));
}

void testFalseCases(){
    std::vector<int> digitsTrue = convertToVector(Config::password);
    digitsTrue[0] = (digitsTrue[0] + 1) % 10;
    TEST_ASSERT_FALSE(checkPassword(digitsTrue, Config::password));

    // Incorrect digit
    int testPassword = 124560;
    std::vector<int> testAttempt = {1, 2, 4, 5, 6, 10};
    TEST_ASSERT_FALSE(checkPassword(testAttempt, testPassword));

    testPassword = 10201030;
    testAttempt = {1, 0, 2, 0, 1, 0, 3, 1};
    TEST_ASSERT_FALSE(checkPassword(testAttempt, testPassword));

    // Incorrect length
    testPassword = 10201030;
    testAttempt = {1, 2, 1, 3, 0};
    TEST_ASSERT_FALSE(checkPassword(testAttempt, testPassword));

    // 0 digits
    testPassword = 10000;
    testAttempt = {1, 0, 0};
    TEST_ASSERT_FALSE(checkPassword(testAttempt, testPassword));
}

int main(){

    std::cout << "testing password function\n" << std::endl;
    std::cout << "using password: " << Config::password << std::endl;
    std::vector<int> digitsTrue = convertToVector(Config::password);

    for (int d: digitsTrue){
        std::cout << d << std::endl;
    }

    UNITY_BEGIN();
    RUN_TEST(testTrueCases);
    RUN_TEST(testFalseCases);
    UNITY_END();

    return 0;
}