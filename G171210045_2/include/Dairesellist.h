#ifndef DAIRESELLIST_H
#define DAIRESELLIST_H
#include <iostream>
#include "Stack.h"

using namespace std;

class Dairesellist 
{
private:
    typedef struct dugum{
        int sayi;
        int dugumno;
        dugum *sdugum;
        dugum *odugum;
        Stack* s;        
    }*d;
    d head;
    d current;
    d temp;  
    d tail;
    
public:
    Dairesellist();
    ~Dairesellist();
    void sayiata(string satir);
    void yenidugum(int deger);
    void stackeat();
    void kaydir(bool sagami);
    void dugumdurum(int dugum);
    void yazdir(bool durum);
};


#endif /* DAIRESELLIST_H */

