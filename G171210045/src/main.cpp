/*         * @file  main.cpp  
           * @description Program buradan başlıyor.
           * @course  2-B  
           * @assignment  1.ödev   
           * @date  27.10.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */ 
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "Yonetim.h"
using namespace std;


int main(int argc, char** argv) 
{
    yonetim *y=new yonetim("./doc/Okul.txt");
    y->ogrencileri_ve_siniflari_ata();  
    y->yaz();
    system("pause");
    return 0;
}

