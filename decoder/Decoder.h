//
// Created by igor on 08.05.19.
//

#ifndef GRAPHBUILDER_DECODER_H
#define GRAPHBUILDER_DECODER_H

#include <string>
#include <map>

bool isletter(char c);

class Result{
public:
    double accumulator;
    std::string rest;

    Result(double accumulator, std::string rest);
};

class MatchParser{
public:
    double Parse(std::string str);

    MatchParser(){
        variables = std::map<std::string, double>();
    };

    void setVariable(std::string variableName, double variableValue);

    double getVariableByName(std::string variableName);

private:
    Result* plusMinus(std::string str);
    Result* Num(std::string str);

    Result* Bracket(std::string str);
    Result* FunctionVariable(std::string str);
    Result* MulDiv(std::string str);
    Result* processFunction(std::string func, Result* result);

    std::map<std::string, double> variables;

};

#endif //GRAPHBUILDER_DECODER_H
