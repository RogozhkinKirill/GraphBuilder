//
// Created by igor on 08.05.19.
//

/*these realization is a simple copy of article, link in the ReadMe.md , but in c++*/

#include <cassert>
#include "Decoder.h"


Result::Result(double accumulator, std::string rest) {
    this->accumulator = accumulator;
    this->rest = rest;
}

double MatchParser::Parse(std::string str) {
    Result *result = plusMinus(str);

    if (result->rest.length() == 0){
        assert("Error: can't parse because of rest.length() == 0");
    }

    return result->accumulator;
}

Result* MatchParser::plusMinus(std::string str) {
    Result *current = Num(str);
    double acc = current->accumulator;

    while(current->rest.length() > 0){

        if (!(current->rest[0] == '+' || current->rest[0] == '-')){
            break;
        }

        char sign = current->rest[0];
        std::string next = current->rest.substr(1);

        acc = current->accumulator;

        current = Num(next);
        if (sign == '+'){
            acc += current->accumulator;
        }
        else{
            acc -= current->accumulator;
        }

        current->accumulator = acc;
    }

    return new Result(current->accumulator, current->rest);
}

Result* MatchParser::Num(std::string str) {
    size_t i = 0;

    bool negative = false;

    if (str[0] == '-'){
        negative = true;
        str = str.substr(1);
    }

    while (i < str.length() && (isdigit(str[i]) || (str[i] == '.'))){
        i++;
    }

    double dPart = atof(str.substr(0, i).c_str());
    if (negative){
        dPart = -dPart;
    }

    std::string restPart = str.substr(i);

    return new Result(dPart, restPart);
}
