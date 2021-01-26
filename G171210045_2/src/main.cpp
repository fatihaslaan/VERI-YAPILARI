/*         * @file  main.cpp  
           * @description Program buradan başlıyor.
           * @course  2-B  
           * @assignment  2.ödev   
           * @date  29.11.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */ 
#include <cstdlib>
#include "Yonetim.h"
using namespace std;

int main(int argc, char** argv) {

    Yonetim *y=new Yonetim("./doc/sayilar.txt");
    y->yaz();
    system("pause");
    return 0;
}

