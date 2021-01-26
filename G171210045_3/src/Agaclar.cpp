/*         * @file  Agaclar.cpp  
           * @description Girilen sayılarla agaclar olusturuluyor
           * @course  2-B  
           * @assignment  3.ödev   
           * @date  16.12.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */
#include "Agaclar.h"
#include "Agac.h"
#include <iostream>
#include <ctime>

using namespace std;

Agaclar::Agaclar(string agacdegeri)
{
    srand(time(NULL));           //sürekli değişmesi için
    agacsayisi=agacdegeri.length();4
    anaagac=NULL;
    while(height(anaagac)<agacsayisi)
    {
        int sayac=height(anaagac);
        al n=new agaclar; 
        n->sag=NULL;
        n->sol=NULL;
        if(anaagac==NULL)
        {
           anaagac=n;
        }
        else
        {
            agacekle(anaagac,n);
        }
        n->uzunluk=agacdegeri[height(anaagac)]-'0';
        n->agac=new Agac(n->uzunluk);
    }   
}

void Agaclar::duzenle(agaclar *&agac)
{
    agaclar *tmp=new agaclar;            //max ve min değerler çıktıktan sonra ağacın bozulma ihtimaline karşı
    if(agac==NULL) return;               //ağacı yeniden kuruyor
    if(agac->sag!=NULL)
    {
        tmp=agac->sag;
        agac->sag=NULL;
        delete(agac->sag);
        agacekle(anaagac,tmp);                    
    }
    if(agac->sol!=NULL)
    {
        tmp=agac->sol;
        agac->sol=NULL;
        delete(agac->sol);
        agacekle(anaagac,tmp);
    }    
    duzenle(agac->sag);
    duzenle(agac->sol);
}

int Agaclar::height(agaclar* a)
{
    if(a==NULL)
    {
        return -1;
    }        
    else
    { 
        return 1+max(height(a->sol),height(a->sag));
    } 
}

void Agaclar::agacekle(agaclar *&eski,agaclar *yeni)
{
   if(eski == NULL) 
    {
        eski = yeni;
    }
    else if(yeni->uzunluk <= eski->uzunluk)
	agacekle(eski->sol,yeni);
    else if(yeni->uzunluk > eski->uzunluk)
	agacekle(eski->sag,yeni);
    else return; 
}

void Agaclar::levelorderyazdir()
{
    for(int i=0;i<agacsayisi+1;i++)
    {   
        seviye(anaagac,i,true,false,false);
    }
}

void Agaclar::seviye(agaclar *&a, int seviyedeger,bool level,bool max,bool min)  //level order mantığını kullanarak max ve minleri yazdırmak istedim
{                                                                            // bu yüzden bool değişkenler kullandım ve hepsini bir fonksiyonda hallettim
    if(a == NULL) return;    
    if(seviyedeger == 0)
    { 
        if(a->agac!=NULL)
        {
            if(level)
                a->agac->levelorder();
            if(max)
            {
                int gecici=a->agac->getmax();
                if(gecici!=0)
                    cout<<"MAX:"<<gecici<<endl;
            }
            if(min)
            {
                int gecici=a->agac->getmin();
                if(gecici!=0)
                    cout<<"MIN:"<<gecici<<endl;
            }
            if(max||min)
            {
                a->uzunluk=a->agac->getyukseklik();   //max veya min olması farketmez eğer eleman silindiyse ağac bitmişmi diye bakıyor
                if(a->uzunluk==-1)
                {
                    agaclar *tmp=new agaclar;
                    tmp=a;
                    agacsayisi--;
                    a=NULL;
                    delete(a);
                    if(tmp->sag!=NULL)
                        agacekle(anaagac,tmp->sag);
                    if(tmp->sol!=NULL)
                        agacekle(anaagac,tmp->sol); 
                }
            }
        }
    }
    else{
	seviye(a->sol,seviyedeger-1,level,max,min);
	seviye(a->sag,seviyedeger-1,level,max,min);
    } 
}

void Agaclar::maxyaz()
{
    int gecici=agacsayisi;
    for(int i=0;i<gecici+1;i++)
    {       
        seviye(anaagac,i,false,true,false);
    }
    duzenle(anaagac);
}

void Agaclar::minyaz()
{
    int gecici=agacsayisi;
    for(int i=0;i<gecici;i++)
    {       
        seviye(anaagac,i,false,false,true);        
    }
    duzenle(anaagac);
}

void Agaclar::deleteagaclar(agaclar*& agac)
{
    if(agac==NULL) return;
    if(agac->sag==NULL&&agac->sol==NULL)
    {
        agac->agac->~Agac();
        agac=NULL;
        delete(agac);
    }
    if(agac!=NULL)
    {    
        deleteagaclar(agac->sag);
        deleteagaclar(agac->sol);
    }
}

Agaclar::~Agaclar()
{
    deleteagaclar(anaagac);    
}