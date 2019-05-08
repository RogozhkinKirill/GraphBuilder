//
// Created by igor on 08.05.19.
//

#ifndef GRAPHBUILDER_DECODER_H
#define GRAPHBUILDER_DECODER_H

#include <string>

class Result{
public:
    double accumulator;
    std::string rest;

    Result(double accumulator, std::string rest);
};

class MatchParser{
public:
    double Parse(std::string str);

    MatchParser(){};
private:
    Result* plusMinus(std::string str);
    Result* Num(std::string str);

};

#endif //GRAPHBUILDER_DECODER_H
