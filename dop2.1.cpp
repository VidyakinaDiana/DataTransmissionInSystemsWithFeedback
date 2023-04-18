//
// Created by smary on 26.03.2023.
//
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

void modelprog1(FILE* file1, FILE* file2) {
    srand(time(NULL));
    double p = 0;
    double f;
    double f_teor = 0;
    int N = 0;
    int t = 0;
    int T = 2;
    while(p < 0.9){
        N = 0;
        std::cout <<"p = " << p << std::endl;
        for(int j = 0; j < 10000; j++) {
            N++;
            if(j == 0)
                std::cout << ++t<< " send m"<< (int)(p*10)  << std::endl;
            f = (double) (rand()) / RAND_MAX;
            //std::cout << f << std::endl;
            while (f <= p) {
                if(j == 0) {
                    t= t+T;
                    std::cout << t<< " get - m"<< (int)(p*10)  << std::endl;
                }
                N++;
                f = (double) (rand()) / RAND_MAX;

                if(j == 0) {
                    t++;
                    std::cout << t<< " send again m"<< (int)(p*10)<< " try "<< N  << std::endl;
                }
                //  std::cout << f << std::endl;
            }
            if(j == 0) {
                t= t+T;
                std::cout << t<< " get + m"<< (int)(p*10)  << std::endl;
            }
        }
        f_teor = 1 / (1 - p);
        fprintf(file1, "%f", p);
        fprintf(file1, "%s", " ");
        fprintf(file1, "%f", (float)N/10000);
        fprintf(file1, "%s", "\n");
        fprintf(file2, "%f", p);
        fprintf(file2, "%s", " ");
        fprintf(file2, "%f", f_teor);
        fprintf(file2, "%s", "\n");
            p += 0.1;
    }
}
