#ifndef YONETIM_H
#define YONETIM_H
#include <iostream>
#include <cstddef>
#include <cstdlib>

using namespace std;

class yonetim{
    
private:
    
    string satir;
    
public:
    yonetim(string text);
    void ogrencileri_ve_siniflari_ata();
    void yaz();   
    
};


#endif /* YONETIM_H */

