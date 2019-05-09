#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>

#include "decoder/Decoder.h"
#include "checker/Checker.h"
#include "tests/tests.h"
#include "checker/utils/EmptyStringException.h"



int main() {
    Checker *ch = new Checker();

    //char *test = "22";
    //char* test = "3.14/2+1/2";
    //char* test = "**sin(-3.14)";
    //char* test = "2.2*2^3";
    char* test = "1+x";
    ch->check(test);
    MatchParser *mp = new MatchParser();
    mp->setVariable("x", 3.14/2);
    double result = mp->Parse(test);

    std::cout << "input: " << test << std::endl;
    std::cout << "result: " << result << std::endl;

    mp->setVariable("x", 1);
    result = mp->Parse(test);
    std::cout << "input: " << test << std::endl;
    std::cout << "result: " << result << std::endl;
    return 0;
}


