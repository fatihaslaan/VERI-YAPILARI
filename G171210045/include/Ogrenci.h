#ifndef OGRENCI_H
#define OGRENCI_H
#include <iostream>
#include <cstddef>
#include <cstdlib>

class ogrenci 
{
private:
    typedef struct ogrencinode{
        char ogrencino;
        ogrencinode *sogrenci;
        ogrencinode *oogrenci;
    }*onode;
    onode h;
    onode c;
    onode ilkc;
    onode ikincic;
    onode ucuncuc;
    onode tmp;
    onode tl;
public:
    char ogrencinoal(char ilkogrenci);
    void ogrencidegis(ogrenci *ikinciogrenci,char ilkogrenci,char ikinciogrencic);
    ogrenci();
    ~ogrenci();
    void yeniogrenci(char ogrencino);
    bool yazdir();
    void setc();   
};

#endif /* OGRENCI_H */

