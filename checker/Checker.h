//
// Created by igor on 09.05.19.
//

#ifndef GRAPHBUILDER_CHECKER_H
#define GRAPHBUILDER_CHECKER_H

#include <string>

enum ParseError{
    EMPTYSTRING = 0x14,
    NOSUCHFORMAT = 0x15
};


class Checker{
public:
    std::string check(std::string str);
    std::string constantsPrepared(std::string str);
};

#endif //GRAPHBUILDER_CHECKER_H
