//
// Created by igor on 16.05.19.
//

#ifndef GRAPHBUILDER_FOURIER_H
#define GRAPHBUILDER_FOURIER_H

#include <complex>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

typedef std::complex<double> base;
typedef std::vector<base> vectorBase;

vectorBase fastFourierTransform(const vectorBase &input);
vectorBase fastReverseFourierTransform(const vectorBase &input);
void printTransformResult(const vectorBase &input, std::string msg, size_t n);

#endif //GRAPHBUILDER_FOURIER_H
