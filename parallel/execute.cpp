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

    unsigned int i = 0;
    static int threadId;
    omp_set_num_threads(5);

    static double startTime = omp_get_wtime();

    MatchParser *mp = new MatchParser();
    #pragma omp parallel
    {

        #pragma omp single
        for (i = 0; i < size; i++){
            if (output[i] == 0.0) {
                mp->setVariable("x", input[i]);
                output[i] = mp->Parse(str);
            }
        }
    }

    static double endTime = omp_get_wtime();
    static double totalTime = endTime - startTime;
    std::cout << "Executing time: " << totalTime << std::endl;


    return output;
}

