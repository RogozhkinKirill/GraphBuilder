#include <iostream>
#include <string>
#include <cmath>

#include "decoder/Decoder.h"
#include "tests/tests.h"

int main() {

    //std::string test = "sin(3.14/2)+cos(3.14/2)";
    //std::string test = "3.14/2+1/2";
    //std::string test = "sin(-3.14)";
    std::string test = "2^3+1/2";

    MatchParser *mp = new MatchParser();
    mp->setVariable("x", -2.0);
    double result = mp->Parse(test);

    std::cout << "result: " << result << std::endl ;
    return 0;
}