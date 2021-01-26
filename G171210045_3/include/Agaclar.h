#include "Agac.h"
#include <string.h>
#include <string>
using namespace std;
#ifndef AGACLAR_H
#define AGACLAR_H

class Agaclar
{
private:
    typedef struct agaclar{
        agaclar* sol;
        agaclar* sag;
        int uzunluk;
        Agac* agac;
    }*al; 
    int agacsayisi;
    al anaagac;
    
    void agacekle(agaclar *&eski,agaclar *yeni);
    int height(agaclar* a);
    void seviye(agaclar *&a,int seviyedeger,bool level,bool max,bool min);
    void duzenle(agaclar *&a);
    void deleteagaclar(agaclar *&a);
public:
    Agaclar(string agacdegeri);
    void levelorderyazdir();
    void minyaz();
    void maxyaz();
    ~Agaclar();   
};


#endif /* AGACLAR_H */

