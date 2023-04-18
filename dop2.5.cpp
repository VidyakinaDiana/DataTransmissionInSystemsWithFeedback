
//
// Created by smary on 26.03.2023.
//
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "dop2.5.hpp"
void modelprog6(FILE* file1,FILE* file2) {
    srand(time(NULL));
    double p = 0;
    double f;
    double f_teor = 0;
    int N;
    double t;
    int pointer = 0;
    std::cout<<"Input T fot 2.5 : ";
    std::cin >> t;
    //std::cout<<"Input p fot 2.5 : ";
   // std::cin >> p;
    double *mas = new double[(int)t];
    f_teor = (1 - p) / (1 + p*t);
   // std::cout << "n ========" <<  f_teor << std::endl;
   // N = 1;
    int i = 0;
    int k=0;
    int m =0;
    int ta = 0;

    while(p<=1){
        f = (double) (rand()) / RAND_MAX; //1
        pointer++;
        if(p ==0.5)
            std::cout << pointer << ": send m" << i++ << std::endl;
        //ta++;
        for(int  j = 0; j < t;j++){
            mas[j] = (double) (rand()) / RAND_MAX; //t
            pointer++;
            if(p ==0.5)
                std::cout << pointer << ": send m" << i++ << std::endl;
          //  ta++;
        }
        for(int c= 0 ;c<10;c++){
            while(f < p){
                pointer++;
               if(p ==0.5)
                   std::cout << pointer-1 << ": get  -  from m " << k << std::endl;
                f = (double) (rand()) / RAND_MAX; //t
                ta++;
                for (int i = 0; i <= t; i++) {
                    if(p ==0.5)
                        std::cout << pointer + i << ": send again m" << m << std::endl;
                    m++;
                }
                pointer += t;
                ta+=t;
                m = k;

            }
            f = mas[0];
            for (int i = 0; i < t - 1; i++) {
                mas[i] = mas[i + 1];
                mas[(int) t - 1] = (double) (rand()) / RAND_MAX;
            }
            pointer++;
            ta++;
           if(p ==0.5)
                std::cout << pointer-1 << ": get + m" << k << std::endl;
            i++;
            if(p ==0.5)
              std::cout << pointer << ": send m" << i << std::endl;
            k++;
            m = k;

        }
       // std::cout << ta << std::endl;
        fprintf(file1, "%f", p);
        fprintf(file1, "%s", " ");
        fprintf(file1, "%f", (double )10/ta);
        fprintf(file1, "%s", "\n");
        ta = 0;
        f_teor = (1 - p) / (1 + p*t);
        fprintf(file2, "%f", p);
        fprintf(file2, "%s", " ");
        fprintf(file2, "%f", f_teor);
        fprintf(file2, "%s", "\n");
        p += 0.1;
        i=0;
        m=0;
        k=0;
    }
 }
