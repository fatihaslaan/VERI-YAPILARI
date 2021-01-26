#ifndef AGAC_H
#define AGAC_H

class Agac
{
private:
    typedef struct dugum
    {
        int deger;
        dugum* sag;
        dugum* sol;        
    }*d;
    int yukseklik;
    d ilkeleman;
    
    void elemanekle(dugum *&eski,dugum *yeni);
    int height(dugum *d);
    void seviye(dugum *d,int seviyedeger);
    int maxdeger(dugum *&d);
    int mindeger(dugum *&d);
    void deleteagac(dugum *&d);
public:
    Agac(int yukseklik);
    ~Agac();
    int getmax();
    int getmin();
    int getyukseklik();
    void levelorder();    
};


#endif /* AGAC_H */

