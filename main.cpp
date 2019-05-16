#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>

#include "decoder/Decoder.h"
#include "checker/Checker.h"
#include "checker/utils/EmptyStringException.h"
#include "parallel/execute.h"
#include "transforms/fourier.h"

std::string REVERSEMSG = "output of reverse fast fourier transform";
std::string COMMONMSG = "output of fast fourier transform";

void ConsoleInterface(){

    std::cout << "Command list: fourier transform" << std::endl <<
    "reverse fourier transform" << std::endl <<
    "calculate the function at x" << std::endl;

    std::cout << "Enter command: " << std::endl;

    std::string command;

    std::cin >> command;

    if (command == "fourier transform"){

    }

    if (command == "reverse fourier transform"){

    }

    if (command  == "calculate the function at x"){

    }
}

void decoderTests(){
    Checker *ch = new Checker();

    double input[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 1.0, 2.0, 3.0, 4.0,
                      5.0, 6.0, 7.0, 8.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
                      1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    double *output;
    size_t size = 24;
    //std::string test = "22";
    //std::string test = "3.14/2+1/2";
    //std::string test = "sin(-3.14)";
    //std::string test = "2.2*2^3";
    std::string test = "sin(pi/2)";
    //std::string test = "sin(eler/2)";

    test = ch->check(test);

    MatchParser *mp = new MatchParser();
    //mp->setVariable("x", 3.14/2);

    double result = mp->Parse(test);

    //std::cout << "x: " << 3.14/2 << std::endl;
    std::cout << "input: " << test << std::endl;
    std::cout << "result: " << result << std::endl;

    /*output = giveOutput(test, input, size);
    for (int i = 0; i < size; i++){
        std::cout << output[i]  << " ";
    }*/
}

void fourierTests(){
    size_t n;
    double tmp;

    std::cout << "Type degree of polynomial" << std::endl;
    std::cin >> n;

    vectorBase input(n);
    std::cout << "Enter your a0 + a1*x + a2*x^2 + ... (enter only a[i]): " << std::endl;
    for (size_t i = 0; i < n; i++){
        std::cin >> tmp;
        input[i] = tmp;
    }

    vectorBase result = fastFourierTransform(input);
    vectorBase reverseResult = fastReverseFourierTransform(input);

    printTransformResult(result, COMMONMSG, n);
    printTransformResult(reverseResult, REVERSEMSG, n);

    std::cout << "You could see results at output/fourier.txt or output/reverseFourier.txt" << std::endl;
}


int main() {

    //decoderTests();
    fourierTests();

    return 0;
}


