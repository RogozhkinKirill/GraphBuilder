//
// Created by igor on 09.05.19.
//

#ifndef GRAPHBUILDER_EXECUTE_H
#define GRAPHBUILDER_EXECUTE_H

#include <cstddef>
#include <iostream>
#include <omp.h>


void init(double *mass, size_t size);
double* giveOutput(std::string str, double* input, size_t size);

#endif //GRAPHBUILDER_EXECUTE_H
