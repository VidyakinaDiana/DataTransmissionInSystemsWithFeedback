#include <iostream>
#include "dop2.1.hpp"
#include "dop2.2.hpp"
#include "dop2.3.hpp"
#include "dop2.4.hpp"
#include "dop2.5.hpp"
#include "osnova4.hpp"

int main() {
    //FILE *file1 = fopen("2.1a.txt", "w") ;
    //FILE *file2 = fopen("2.1b.txt", "w") ;
   //modelprog1(file1,file2);

    //FILE *file3 = fopen("2.2a.txt", "w") ;
    //FILE *file4 = fopen("2.2b.txt", "w") ;
   // modelprog2(file3,file4);

   // FILE *file5 = fopen("2.3a.txt", "w") ;
    //FILE *file6 = fopen("2.3b.txt", "w") ;
    //modelprog3(file5,file6);

 /* FILE *file7 = fopen("2.3c.txt", "w") ;
   FILE *file8 = fopen("2.3d.txt", "w") ;
   modelprog4(file7,file8);*/

   // FILE *file9 = fopen("2.4a.txt", "w") ;
    //FILE *file11 = fopen("2.4b.txt", "w") ;
    //modelprog5(file9, file11);

   //FILE *file10 = fopen("2.5a.txt", "w") ;
   //FILE *file12 = fopen("2.5b.txt", "w") ;
   //modelprog6(file10,file12);

   FILE *file13 = fopen("osnova.txt", "w") ;
    osnova4(file13);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
