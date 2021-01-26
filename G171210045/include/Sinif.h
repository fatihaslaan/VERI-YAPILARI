#ifndef SINIF_H
#define SINIF_H
#include "Ogrenci.h"

using namespace std;

class sinif 
{
private:
    typedef struct sinifnode{
        int sinifno;
        sinifnode *ssinif;
        sinifnode *osinif;
        ogrenci* o;        
    }*snode;
    snode head;
    snode current;
    snode ikincicurrent;
    snode currentilko;
    snode currentikincio;
    snode temp;  
    snode tail;
    bool devamivarmi;
    
public:
    sinif();
    ~sinif();
    void yenisinif(int sinifno);
    void siradegistir(int ilksinif,int ikincisinif);
    void ogrencidegistir(char ilkogrenci,char ikinciogrenci);
    void yeniogrenci(string ogrenciler);
    void yazdir();
    void setogrencic();
};


#endif /* LIST_H */

