#pragma once

namespace Pins {
    namespace DTMF{
        constexpr int in = 4;
        constexpr int StQ = 14;
        constexpr int Q4 = 15;
        constexpr int Q3 = 27;
        constexpr int Q2 = 26;
        constexpr int Q1 = 25;
    }

    constexpr int battVolt = 35;
    constexpr int battCharge = 34;
    constexpr int voltPresent = 9;
    constexpr int solenoid = 33;
}

namespace Config{
    constexpr int password = 271828;
}