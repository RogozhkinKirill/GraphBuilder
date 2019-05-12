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
    void check(char* str);
};

#endif //GRAPHBUILDER_CHECKER_H
