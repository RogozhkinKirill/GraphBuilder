//
// Created by igor on 16.05.19.
//

#include "fourier.h"
#include "../constants/Constants.h"


/* implementation of discrete fast Fourier Transform the realization based on proto-code from Kormen*/

vectorBase fastFourierTransform(const vectorBase &input) {
    size_t n = input.size();

    if (n == 1){
        return vectorBase(1, input[0]);
    }

    vectorBase w(n);
    for (size_t i = 0; i < n; i++){
        double alpha = 2 * PI * i / n;
        w[i] = base(cos(alpha), sin(alpha));
    }

    vectorBase A(n / 2), B(n / 2);
    for (size_t i = 0; i < n / 2; i++){
         A[i] = input[i * 2];
         B[i] = input[i * 2 + 1];
    }

    vectorBase Av = fastFourierTransform(A);
    vectorBase Bv = fastFourierTransform(B);

    vectorBase result(n);

    for (size_t i = 0; i < n; i++){
        result[i] = Av[i % (n / 2)] + w[i] * Bv[i % (n / 2)];
    }

    return result;
}

vectorBase fastReverseFourierTransform(const vectorBase &input) {
    vectorBase result = fastFourierTransform(input);

    for (size_t i = 0; i < result.size(); i++){
        result[i] /= input.size();
    }
    reverse(result.begin() + 1, result.end());
    return result;
}

void printTransformResult(const vectorBase &input, std::string msg, size_t n) {


    std::ofstream fourier;
    if (msg == "output of fast fourier transform"){
        fourier.open("../output/fourier.txt");
        fourier.clear();
    }

    if (msg == "output of reverse fast fourier transform"){
        fourier.open("../output/reverseFourier.txt");
        fourier.clear();
    }

    fourier << msg << std::endl;
    fourier << "output format: real image" << std::endl;
    for (size_t i = 0; i < n; i++){
        fourier << input[i].real() << " " << input[i].imag() << std::endl;
    }

    fourier.close();
}
