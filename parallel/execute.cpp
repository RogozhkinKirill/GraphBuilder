//
// Created by igor on 09.05.19.
//

#include "execute.h"
#include "../decoder/Decoder.h"

void init(double *mass, size_t size){
    size_t i = 0;

    for (i = 0; i < size; i++){
        mass[i] = 0.0;
    }
}

double* giveOutput(std::string str, double *input, size_t size) {
    double *output = new double[size];
    init(output, size);

    static int threadId;
    omp_set_num_threads(size);

    static double startTime = omp_get_wtime();

    MatchParser *mp = new MatchParser();

    #pragma omp parallel
    {
        threadId = omp_get_thread_num();

        mp->setVariable("x", input[threadId]);
        output[threadId] = mp->Parse(str);
    }

    static double endTime = omp_get_wtime();
    static double totalTime = endTime - startTime;
    std::cout << "Executing time: " <<totalTime <<std::endl;


    return output;
}

