//
// Created by smary on 26.03.2023.
//
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

void modelprog3(FILE* file1, FILE* file2) {
    srand(time(NULL));
    double p = 0;
    double p_obr = 0;
    double f1;
    double f2;
    int t=0;
    int T = 2;
    double f_teor = 0;
    int N=0;
    int k=1;
    while(p < 1 && p_obr < 1){
       // N = 1;
        for(int c =0;c<100;c++) {
            f1 = (double)(rand())/ RAND_MAX;
            f2 = (double)(rand())/ RAND_MAX;
            if((p == 0.7) && (p_obr == 0.7))
                std::cout<< t++ <<" send m"<<c<<std::endl;
            N++;
            while ((f1 < p) || (f2 < p_obr)) {
                f1 = (double) (rand()) / RAND_MAX;
               // N=N+T+1;
                f2 = (double) (rand()) / RAND_MAX;
                N++;
                if(p == 0.7 && p_obr == 0.7) {
                    t = t+T;
                    std::cout<<t-1<<" get - m" << c << std::endl;
                    std::cout<<N<< std::endl;
                }
                k++;
                if(p == 0.7 && p_obr == 0.7)
                    std::cout<<t++ <<"send again m"<<c<<" try "<< k <<std::endl;

            }
            if(p == 0.7 && p_obr == 0.7) {
                t = t+T;
                std::cout<<t-1<<" get + m" << c << std::endl;
            }
            k=1;
        }
        f_teor = ((1-p)*(1-p_obr))/pow((1-p+p*p_obr-p_obr),2);
        fprintf(file1, "%f", p_obr);
        fprintf(file1, "%s", " ");
        fprintf(file1, "%f", p);
        fprintf(file1, "%s", " ");
      //  std::cout<<N<<std::endl;
        fprintf(file1, "%f", (double)N/100);
        fprintf(file1, "%s", "\n");

        fprintf(file2, "%f", p_obr);
        fprintf(file2, "%s", " ");
        fprintf(file2, "%f", p);
        fprintf(file2, "%s", " ");
        fprintf(file2, "%f", f_teor);
        fprintf(file2, "%s", "\n");
       // f_teor=0;
        N=0;
        p += 0.1;
        if(p >= 0.9)
        {
            p = 0;
            p_obr +=0.1;
        }
    }
}

void modelprog4(FILE* file1, FILE* file2) {
    srand(time(NULL));
    double p = 0;
    double p_obr = 0;
    double f1;
    double f2;
    double f_teor = 0;
    int N =0;
    int T=2;
    int n;
    int t=0;
    std::cout<<"Input n fot 2.3 : ";
    std::cin >> n;
        while (p <= 1 && p_obr <= 1) {
            int temp_n ;
          //  N = 1;

            for(int c=0;c<100;c++) {
                f1 = (double) (rand()) / RAND_MAX;
                f2 = (double) (rand()) / RAND_MAX;
                if((p == 0.1) && (p_obr == 0.1))
                    std::cout<< t++ <<" send m"<<c<<std::endl;
                temp_n = n-1;
                N++;
                while ((f1 < p || f2 < p_obr) && temp_n > 0) {
                    f1 = (double) (rand()) / RAND_MAX;
                    N++;
                   // N=N+T+1;
                    f2 = (double) (rand()) / RAND_MAX;
                    temp_n--;
                    if(p == 0.1 && p_obr == 0.1) {
                        t = t+T ;
                        std::cout<<t-1<<" get - m" << c << std::endl;

                    }
                    if(p == 0.1 && p_obr == 0.1)
                        std::cout<<t++ <<"send again m"<<c<<" try " << n-temp_n<<std::endl;
                }
                if(p == 0.1 && p_obr == 0.1) {
                    t = t+T;
                    std::cout<<t-1<<" get + m" << c << std::endl;
                }
            }
            t=0;
            f_teor = (1-pow((p-p*p_obr+p_obr),n))/(1-p+p*p_obr-p_obr);
            fprintf(file1, "%f", p_obr);
            fprintf(file1, "%s", " ");
            fprintf(file1, "%f", p);
            fprintf(file1, "%s", " ");
            fprintf(file1, "%f", (double )N/100);
         //   std::cout<<N<<std::endl;
            fprintf(file1, "%s", "\n");
            N=0;
            fprintf(file2, "%f", p_obr);
            fprintf(file2, "%s", " ");
            fprintf(file2, "%f", p);
            fprintf(file2, "%s", " ");
            fprintf(file2, "%f", f_teor);
            fprintf(file2, "%s", "\n");
            p += 0.1;
            if (p >= 1) {
                p = 0;
                p_obr += 0.1;
            }

        }
}