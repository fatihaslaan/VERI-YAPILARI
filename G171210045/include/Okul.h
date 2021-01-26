#ifndef OKUL_H
#define OKUL_H
#include "Sinif.h"

using namespace std;

class okul
{
private:
   sinif* okulnode;    
    
public:
    okul();
    ~okul();
    void yenisinif(int sinifno);
    void yeniogrenci(string ogrenciler);
    void yazdir();
    void ogrencidegistir(char ilkogrenci,char ikinciogrenci);  
    void sinifdegistir(int ilksinif,int ikincisinif);   
    void set();
};





#endif /* OKUL_H */

