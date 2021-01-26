/*         * @file  main.cpp  
           * @description Program burda başlıyor.
           * @course  2-B  
           * @assignment  3.ödev   
           * @date  16.12.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */
#include <cstdlib>
#include "Yonetim.h"
using namespace std;


int main(int argc, char** argv) 
{
    Yonetim *y=new Yonetim();
    y->yaz();
    return 0;
}

