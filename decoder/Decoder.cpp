//
// Created by igor on 08.05.19.
//

/*this realization is a simple copy of article, link in the ReadMe.md , but in c++*/

#include <cassert>
#include <cmath>
#include <iostream>
#include <set>

#include "Decoder.h"


Result::Result(double accumulator, std::string rest) {
    this->accumulator = accumulator;
    this->rest = rest;
}

double MatchParser::Parse(std::string str) {
    Result *result = plusMinus(str);

    if (!result->rest.empty()){
        assert("Error: can't parse");
    }

    return result->accumulator;
}

Result* MatchParser::plusMinus(std::string str) {
    Result *current = MulDiv(str);
    double acc = current->accumulator;

    while(current->rest.length() > 0){

        if (!(current->rest[0] == '+' || current->rest[0] == '-')){
            break;
        }

        char sign = current->rest[0];
        std::string next = current->rest.substr(1);

        acc = current->accumulator;

        current = MulDiv(next);
        if (sign == '+'){
            acc += current->accumulator;
        }
        else{
            acc -= current->accumulator;
        }

    }

    return new Result(acc, current->rest);
}

Result *MatchParser::Bracket(std::string str) {
    char zeroChar = str[0];
    if (zeroChar == '('){
        Result *result = plusMinus(str.substr(1));

        if (!result->rest.empty() && result->rest[0] == ')'){
            result->rest = result->rest.substr(1);
        }
        else{
            assert("Error: 2n + 1 brackets");
        }

        return result;
    }

    return FunctionVariable(str);
}

Result *MatchParser::FunctionVariable(std::string str) {
    std::string fun;
    size_t i = 0;
    while(i < str.length() && ((isletter(str[i])) || (isdigit(str[i]) && i > 0))){
        fun.push_back(str[i]);
        i++;
    }

    if (!fun.empty()){
        if (str.length() > i && str[i] == '('){
            Result *result = Bracket(str.substr(fun.length()));

            return processFunction(fun, result);
        }
        else{
            return new Result(getVariableByName(fun), str.substr(fun.length()));
        }
    }

    return Num(str);
}

Result *MatchParser::MulDiv(std::string str) {
    Result *current = Bracket(str);

    double acc = current->accumulator;

    while(true){
        if (current->rest.length() == 0){
            return current;
        }
        char sign = current->rest[0];

        if (sign != '*' && sign != '/' && sign!= '^'){
            return current;
        }

        std::string next = current->rest.substr(1);
        Result *right = Bracket(next);

        if (sign == '*'){
            acc *= right->accumulator;
        }
        if (sign == '/'){
            acc /= right->accumulator;
        }
        if (sign == '^'){
            acc = pow(acc, right->accumulator);
        }

        current = new Result(acc, right->rest);
    }
}

Result *MatchParser::processFunction(std::string func, Result *result) {
    if (func == "sin"){
        return new Result(sin(result->accumulator), result->rest);
    }

    else if (func == "cos"){
        return new Result(cos(result->accumulator), result->rest);
    }

    else if (func == "tan"){
        return new Result(tan(result->accumulator), result->rest);
    }

    else if (func == "ln"){
        return new Result(log(result->accumulator), result->rest);
    }

    else if (func == "exp"){
        return new Result(exp(result->accumulator), result->rest);
    }

    else if (func == "arcsin"){
        return new Result(asin(result->accumulator), result->rest);
    }

    else if (func == "abs"){
        return new Result(std::abs(result->accumulator), result->rest);
    }

    else if (func == "log10"){
        return new Result(log10(result->accumulator), result->rest);
    }

    else{
        perror("Error: function is not defined");
    }
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




double MatchParser::getVariableByName(std::string variableName) {
    std::map<std::string, double>::iterator itr = this->variables.find(variableName) ;

   if (itr != this->variables.end()){
            return itr->second;
   }


    else{
            assert("there is no such variable");

            return 0.0;
    }

}

void MatchParser::setVariable(std::string variableName, double variableValue) {
    if (!this->variables.empty()){
        std::map<std::string, double>::iterator itr = this->variables.find(variableName);
        itr->second = variableValue;
    }

    else{
        this->variables.insert({variableName, variableValue});
    }
}


bool isletter(char c) {
    std::set<char> alphabet = {'a', 'b', 'c', 'd', 'e',
                               'f', 'g', 'i', 'j', 'k',
                               'l', 'm', 'n', 'o', 'p',
                               't', 'r', 'u','x', 'y',
                               'z', 'q', 'w', 'v', 's', 'h'};
    if (alphabet.count(c) == 0){
        return false;
    }

    else{
        return true;
    }
}
