//
// Created by igor on 09.05.19.
//

#ifndef GRAPHBUILDER_EMPTYSTRINGEXCEPTION_H
#define GRAPHBUILDER_EMPTYSTRINGEXCEPTION_H


#include <bits/exception.h>

class EmptyStringException: public std::exception{
public:
    const char * what () const throw ()
    {
        return "EmptyStringException";
    }
};

#endif //GRAPHBUILDER_EMPTYSTRINGEXCEPTION_H
