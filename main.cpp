#include <iostream>
#include <string>

#include "decoder/Decoder.h"
#include "tests/tests.h"

int main() {

    std::string test = "10.1-8.1+2.2+6.0";

    MatchParser *mp = new MatchParser();

    double result = mp->Parse(test);

    std::cout << result;

    return 0;
}