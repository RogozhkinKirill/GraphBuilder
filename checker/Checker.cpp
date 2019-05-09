//
// Created by igor on 09.05.19.
//
#include "Checker.h"
#include "utils/NoSuchFormatException.h"
#include "utils/EmptyStringException.h"

#include <set>
#include <iostream>
#include <cstring>

void Checker::check(char* str) {
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
                if (strstr(str, (*itr).c_str())) {
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
}
