//
// Created by smary on 26.03.2023.
//
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

void modelprog2(FILE *file1, FILE *file2) {
    srand(time(NULL));
    double p = 0;
    double f;
    double f_teor = 0;
    int N = 0;
    int n;
    double raz;
    int t=0;
    int T = 2;
    std::cout<<"Input n fot 2.2 : ";
    std::cin >> n;
    int n_1 =0;
  //  while(n_1<n) {
        while (p <= 1) {
            N = 0;
            std::cout <<"p = " << p << std::endl;
            for (int j = 0; j < 10000; j++){
               // std::cout << N++  << std::endl;
               N++;
                if(j == 0)
                    std::cout << ++t<< " send m"<< (int)(p*10)  << std::endl;
                int temp_n = n;

                f = (double) (rand()) / RAND_MAX;
                while (f <= p && temp_n > 1) {
                    N++;
                    if(j == 0) {
                        t= t+T;
                        std::cout << t<< " get - m"<< (int)(p*10)  << std::endl;
                    }
                    f = (double) (rand()) / RAND_MAX;
                    temp_n--;
                    if(j == 0) {
                        t++;
                        std::cout << t<< " send again m"<< (int)(p*10)  << std::endl;
                    }
                }
                if(j == 0) {
                    t= t+T;
                    std::cout << t<< " get + m"<< (int)(p*10)<< " try "<< N  << std::endl;
                }
            }
            if(p == 1)
                raz =0;
            else raz = 1 -p;
            f_teor = (pow(p,n)-1)/(p-1);
          //  fprintf(file1, "%d", n_1);
          //  fprintf(file1, "%s", " ");
            fprintf(file1, "%f", p);
            fprintf(file1, "%s", " ");
            fprintf(file1, "%f", (double )N/10000);
            fprintf(file1, "%s", "\n");
           // fprintf(file2, "%d", n_1);
            //fprintf(file2, "%s", " ");
            fprintf(file2, "%f", p);
            fprintf(file2, "%s", " ");
            fprintf(file2, "%f", f_teor);
            fprintf(file2, "%s", "\n");
            if(p < 0.9)
               p += 0.1;
            else
                p += 0.01;
        }
        p = 0;
       // n_1++;
  //  }
}
