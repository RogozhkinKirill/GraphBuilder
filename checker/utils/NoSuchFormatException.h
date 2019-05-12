//
// Created by igor on 09.05.19.
//

#ifndef GRAPHBUILDER_NOSUCHFORMATEXCEPTION_H
#define GRAPHBUILDER_NOSUCHFORMATEXCEPTION_H

#include <bits/exception.h>

class NoSuchFormatException: public std::exception{
public:
    const char * what () const throw ()
    {
        return "NoSuchFormatException";
    }
};
#endif //GRAPHBUILDER_NOSUCHFORMATEXCEPTION_H
