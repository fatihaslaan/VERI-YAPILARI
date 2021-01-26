/*         * @file  Agac.cpp  
           * @description Oluşan agaclara buralarda uzunlukları kadar rasgele degerler atanıyor.
           * @course  2-B  
           * @assignment  3.ödev   
           * @date  16.12.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */
#include "Agac.h"
#include <algorithm>
#include <iostream>

using namespace std;

Agac::Agac(int yukseklik)
{
    
    this->yukseklik=yukseklik; 
    ilkeleman=NULL;
    while(height(ilkeleman)<yukseklik)
    {
        d n=new dugum;
        n->sag=NULL;                 //ileride kolaylık sağlamak için başlangıçta null atıyoruz
        n->sol=NULL;             
        n->deger=rand()%600+1;          
        if(ilkeleman==NULL)
        {
           ilkeleman=n;
        }
        else
        {
            elemanekle(ilkeleman,n);
        }
    }
}

int Agac::height(dugum *d)
{
    if(d==NULL)
    {
        return -1;
    }        
    else
    { 
        return 1+max(height(d->sol),height(d->sag));    //maximum yukseklik
    }   
}

void Agac::elemanekle(dugum *&eski, dugum *yeni)
{    
    if(eski == NULL) 
    {
        eski = yeni;
    }
    else if(yeni->deger < eski->deger)
		elemanekle(eski->sol,yeni);     //değerlere göre eleman ekliyor
    else if(yeni->deger > eski->deger)
		elemanekle(eski->sag,yeni);
    else return; 
		
}

void Agac::seviye(dugum *d, int seviyedeger)
{
    if(d == NULL) 
        return;    
    if(seviyedeger == 0) 
        cout<<d->deger<<" ";
    else
    {
		seviye(d->sol,seviyedeger-1);   //level order
		seviye(d->sag,seviyedeger-1);
    } 
}

void Agac::levelorder()
{
    for(int i=0;i<1+yukseklik;i++)
    {       
        seviye(ilkeleman,i);
    }
    cout<<endl;
}

int Agac::maxdeger(dugum *&d)
{
    if(d==NULL)
        return 0;
    if(d->sag==NULL)
    {
        int gecici=d->deger;   //max degeri bulup
        d=d->sol;            //düğümü siliyoruz
        yukseklik=height(ilkeleman);
        return gecici;
    }
    else
        maxdeger(d->sag);    
}
int Agac::mindeger(dugum *&d)
{
    if(d==NULL)
        return 0;
    if(d->sol==NULL)
    {
        int gecici=d->deger;    //min degeri bulup döndürdükten sonra siliyoruz
        d=d->sag;
        yukseklik=height(ilkeleman);
        return gecici;
    }
    else
        mindeger(d->sol);
}

int Agac::getmax()
{
    return maxdeger(ilkeleman);
}

int Agac::getmin()
{
    return mindeger(ilkeleman);
}

int Agac::getyukseklik()
{
    return yukseklik;
}

void Agac::deleteagac(dugum *&d)
{
    if(d==NULL) return;
    if(d->sag==NULL&&d->sol==NULL)
    {
        d=NULL;          //ağacı siliyoruz
        delete(d);
    }
    if(d!=NULL)
    {    
        deleteagac(d->sag);
        deleteagac(d->sol);
    }
}

Agac::~Agac()
{
    deleteagac(ilkeleman);    
}
