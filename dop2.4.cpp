//
// Created by smary on 26.03.2023.
//
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "dop2.4.hpp"
void modelprog5(FILE* file1,FILE* file2) {
    srand(time(NULL));
    double p = 0;
    double f;
    double f_teor = 0;
    int N;
    double t;
    int ta = 0;
    int pointer = 0;
    std::cout<<"Input T fot 2.4 : ";
    std::cin >> t;
   // t = t+1;
    N = 1;
    int k = 0;
    int i = 0;
        while (p <= 1) {
            for (int j = 0; j < 10000; j++) {
                f = (double) (rand()) / RAND_MAX;
               pointer = pointer + 1;
                ta++;
                if(p == 0.1)
                    std::cout << pointer << ": send m" << j << std::endl;

                while (f < p) {
                    pointer = pointer + t;
                    ta+=t;
                    if(p == 0.1 )
                       std::cout << pointer << ": get - " << std::endl;
                    N++;
                    f = (double) (rand()) / RAND_MAX;
                   pointer = pointer + 1;
                    ta++;
                    if(p == 0.1)
                         std::cout << pointer << ": send m" << std::endl;
                }
                pointer = pointer + t;
                if(p == 0.1)
                    std::cout << pointer << ": get + " << std::endl;

                ta+=t;
            }

            //std::cout << ta<< std::endl;
            f_teor = (1 - p) / (1 + t);
            fprintf(file1, "%f", p);
            fprintf(file1, "%s", " ");
            fprintf(file1, "%f", (double)10000/ta);
            fprintf(file1, "%s", "\n");
           // std::cout << ta<< std::endl;
            //std::cout << pointer<< std::endl;
             ta = 0;
            fprintf(file2, "%f", p);
            fprintf(file2, "%s", " ");
            fprintf(file2, "%f", f_teor);
            fprintf(file2, "%s", "\n");
            p += 0.1;
            i++;
        }
}