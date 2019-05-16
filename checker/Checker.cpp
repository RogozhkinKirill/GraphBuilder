//
// Created by igor on 09.05.19.
//
#include "Checker.h"
#include "utils/NoSuchFormatException.h"
#include "utils/EmptyStringException.h"
#include "../constants/Constants.h"

#include <set>
#include <iostream>
#include <cstring>
#include <sstream>

std::string Checker::check(std::string str) {
    std::set<std::string> unorder = {"..", "++", "--", "//", "**", "^^",
                                     ".+", "+.", ".-", "-.", "./", "/.",
                                     ".*", "*.", ".^", "^.",
                                     "+-", "-+", "+/", "/+", "+*", "*+", "+^", "^+",
                                     "-/", "/-", "-*", "*-", "-^", "^-",
                                     "/*", "*/", "^/", "/^",
                                     "*^", "^*"};

    std::set<std::string>::iterator itr;

    try {
        if (str == ""){
            throw EmptyStringException();
        }

        else{
            for (itr = unorder.begin(); itr != unorder.end(); ++itr) {
                if (str.find(*itr) != std::string::npos) {
                    throw NoSuchFormatException();
                }
            }
        }

    }catch(NoSuchFormatException &ex){
        std::perror(ex.what());
        std::exit(EMPTYSTRING);
    }catch(EmptyStringException &ex){
        std::perror(ex.what());
        std::exit(NOSUCHFORMAT);
    }

    str = constantsPrepared(str);

    return str;
}


//i know about repeated code, but i am too lazy to execute it in another func(too few constants)
std::string Checker::constantsPrepared(std::string str) {
    size_t foundPi = str.find("pi");
    size_t foundE = str.find("eler");

    std::ostringstream strsPI;
    strsPI << PI;
    std::string strPI = strsPI.str();

    if (foundPi != std::string::npos){
        str.replace(foundPi, 2, strPI);
    }


    std::ostringstream strsE;
    strsE << E;
    std::string strE = strsE.str();

    if (foundE != std::string::npos){
        str.replace(foundE, 4, strE);
    }

    return str;
}
