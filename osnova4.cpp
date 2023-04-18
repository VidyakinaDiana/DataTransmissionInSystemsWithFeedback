//
// Created by smary on 04.04.2023.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
void osnova4(FILE* file) {
    srand(time(NULL));
    double p = 0;
    int exper1= 10;
    int t;
    int L;
    int flag =0;
    int pointer = 0;
    int counter =1;

    double *allM = new double[exper1];
    std::cout<<"Input T : ";
   std::cin >> t;
    std::cout<<"Input L : ";
    std::cin >> L;
    double *buffer = new double[L];
    int *currentMes = new int[t+1];
    int *temp = new int[t+1];

    int numOfGetMes = 0;
    int **qit =new int*[2];
    for(int i =0; i < exper1; i++)
        qit[i] = new int[exper1];
    while(p<=1){

        for(int i = 0; i < exper1; i++){
            allM[i] = (double) (rand()) / RAND_MAX; // генерируем 100 сообщений
            if(i<t+1)
                temp[i]=currentMes[i]=i+1;
            if(i<L)
                buffer[i] =0;
        }

        while(currentMes[0]-1 < exper1) {
            if(currentMes[0] > exper1)break;
           if ( p==0.4 ) {
                std::cout << pointer << ": send mes " << currentMes[0] << std::endl;
                qit[0][currentMes[0]-1] = pointer+t;
                qit[1][currentMes[0]-1] = 1;
                for(int i = 0; i < exper1; i++)
                    if(qit[0][i] == pointer){
                        std::cout << pointer << ": get ";
                        if(qit[1][i] == 0)
                            std::cout <<" + from mes"<< i+1<<std::endl;
                        else if(qit[1][i] == 1)
                            std::cout <<" - from mes"<< i+1<<std::endl;
                        qit[0][i]=0;
                    }
            }
            while (allM[currentMes[0]-1] < p) { // цикл отправки i-ого сообщения, если вышли из цикла, счетчик ++ , учесть отправления сообщений во время задержки
                counter++;
               if (p == 0.4) {
                    std::cout << "send - for mes " << currentMes[0] << std::endl; // отредактировать лог
                    qit[0][currentMes[0]-1] = pointer+t;
                    qit[1][currentMes[0]-1] = 1;
                    for(int i = 0; i < exper1; i++)
                        if(qit[0][i] == pointer){
                            std::cout << pointer << ": get ";
                            if(qit[1][i] == 0)
                                std::cout <<" + from mes"<< i+1<<std::endl;
                            else if(qit[1][i] == 1)
                                std::cout <<" - from mes"<< i+1<<std::endl;
                            qit[0][i]=0;
                        }

                }
                allM[currentMes[0]-1] = (double) (rand()) / RAND_MAX;
                for (int io=1; io < t + 1; io++) {
                    if(currentMes[io] > exper1) break;
                    pointer++;
                    if (p == 0.4) {
                        std::cout << pointer << ": send mes " << currentMes[io] << std::endl;
                        for(int i = 0; i < exper1; i++)
                            if(qit[0][i] == pointer){
                                std::cout << pointer << ": get ";
                                if(qit[1][i] == 0)
                                    std::cout <<" + from mes"<< i+1<<std::endl;
                                else if(qit[1][i] == 1)
                                    std::cout <<" - from mes"<< i+1<<std::endl;
                                qit[0][i]=0;
                            }

                    }
                    if (allM[currentMes[io]] < p) {
                        if (p == 0.4) {
                            std::cout << "send - for mes " << currentMes[io] << std::endl;
                            qit[0][currentMes[io]-1] = pointer+t;
                            qit[1][currentMes[io]-1] = 1;
                        }
                        allM[currentMes[io]] = (double) (rand()) / RAND_MAX;
                    } else {
                        if ((currentMes[io] - currentMes[0] - 1) < L) {
                            buffer[currentMes[io] - currentMes[0] - 1] = currentMes[io];
                        int c = io-flag;
                         while(c<=t) {
                             if(c<t)
                                 temp[c] = temp[c+1];
                             else  temp[c] = temp[c]+1;
                                 c++;
                         }
                         flag++;
                          //  std::cout<< std::endl;
                           if (p == 0.4) {
                                std::cout << "send + for mes " << currentMes[io] << " & BUFFER" << std::endl;
                                qit[0][currentMes[io]-1] = pointer+t;
                                qit[1][currentMes[io]-1] = 0;
                                std::cout << "BUFFER: ";
                                for(int u =0;u<L;u++)
                                    std::cout << buffer[u] << " ";
                                std::cout<<std::endl;
                            }
                            numOfGetMes++;
                        } else {
                            if (p == 0.4) {
                                std::cout << "send - for mes ! " << currentMes[io] << std::endl;
                                qit[0][currentMes[io] - 1] = pointer + t;
                                qit[1][currentMes[io] - 1] = 1;
                            }
                        }
                    }
                }
                pointer++;
                flag=0;



                if (p == 0.4) {
                   // std::cout << pointer-1 << ": get - from mes" << currentMes[0] << std::endl;  //
                    std::cout << pointer << ": send again mes" << currentMes[0] << std::endl;
                    for(int i = 0; i < exper1; i++)
                        if(qit[0][i] == pointer){
                            std::cout << pointer << ": get ";
                            if(qit[1][i] == 0)
                                std::cout <<" + from mes"<< i+1<<std::endl;
                            else if(qit[1][i] == 1)
                                std::cout <<" - from mes"<< i+1<<std::endl;
                            qit[0][i]=0;
                        }
                    qit[0][currentMes[0]-1] = pointer+t;
                    qit[1][currentMes[0]-1] = 1;
                }
                for (int a = 0; a < t + 1; a++)
                    currentMes[a] = temp[a];
            }
          pointer++;

            if (p == 0.4) {
                std::cout << "get mes " << currentMes[0] << " & send +" << std::endl;
                qit[0][currentMes[0]-1] = pointer+t-1;
                qit[1][currentMes[0]-1] = 0;
                std::cout << "-----------------------> " << currentMes[0] << std::endl;
                if (buffer[0] - 1 == currentMes[0]) {
                    std::cout << "from buffer -------------------> ";
                    for (int p = 0; p < L; p++) {
                        if (buffer[p] == 0)break;
                        std::cout << buffer[p] << " ";
                        buffer[p] = 0;
                    }
                    std::cout << std::endl;
                } else {
                    std::cout <<"BUFFER: ";
                    for (int i = 0; i < L - 1; i++) {
                        buffer[i] = buffer[i + 1];
                        std::cout<<buffer[i]<<" ";
                    }

                    buffer[L - 1] = 0;
                    std::cout<<buffer[L-1]<<" ";
                    std::cout<<std::endl;
                }
            }

                for (int c = 0; c < t; c++) {
                    currentMes[c] = currentMes[c + 1];
                }
                currentMes[t] = currentMes[t] + 1;

            for (int a = 0; a < t + 1; a++)
                temp[a] = currentMes[a];
            counter=1;
        }
        for(int j = 0;j<2;j++)
          for(int i =0; i < exper1; i++)
                qit[j][i] = exper1 * exper1;
        fprintf(file, "%f", (double )pointer/exper1);
        fprintf(file, "%s", "\n");
        pointer =1;


        p += 0.1;
    }
}