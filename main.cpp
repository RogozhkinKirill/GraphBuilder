#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>

#include "decoder/Decoder.h"
#include "checker/Checker.h"
#include "tests/tests.h"
#include "checker/utils/EmptyStringException.h"
#include "parallel/execute.h"


int main() {
    Checker *ch = new Checker();

    double input[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 1.0, 2.0, 3.0, 4.0,
                      5.0, 6.0, 7.0, 8.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
                      1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    double *output;
    size_t size = 24;
    //char *test = "22";
    //char* test = "3.14/2+1/2";
    //char* test = "sin(-3.14)";
    //char* test = "2.2*2^3";
    char* test = "sin(1+x)+2*3/3";
    //ch->check(test);
    MatchParser *mp = new MatchParser();
    //mp->setVariable("x", 3.14/2);
    //double result = mp->Parse(test);

    //std::cout << "x: " << 3.14/2 << std::endl;
    //std::cout << "input: " << test << std::endl;
    //std::cout << "result: " << result << std::endl;

    output = giveOutput(test, input, size);
    for (int i = 0; i < size; i++){
        std::cout << output[i]  << " ";
    }
    return 0;
}


