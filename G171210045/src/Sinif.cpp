/*         * @file  Sinif.cpp  
           * @description sınıf eklemeye ve her sınıftaki ogrencileri düzenlemeye yarar.
           * @course  2-B  
           * @assignment  1.ödev   
           * @date  27.10.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */ 
#include <cstddef>
#include "Sinif.h"

using namespace std;

sinif::sinif()
{
    head=NULL;
    temp=NULL;
    current=NULL;
    ikincicurrent=NULL;
    currentilko=NULL;
    currentikincio=NULL;
    devamivarmi=false;
}

void sinif::yenisinif(int sinifno)
{
    snode n=new sinifnode;
    n->ssinif=NULL;
    if(head==NULL)
    {
        head=n;
        temp=n;
        current=n; 
        head->osinif=NULL;
    }
    else
    {        
        n->osinif=temp;
        temp->ssinif=n;
        temp=n;
        current=n;
    }
    n->sinifno=sinifno;     
}

void sinif::yeniogrenci(string ogrenciler)
{
    current->o=new ogrenci();        
    for (int i = 0; i < ogrenciler.length(); i=i+2)
    {
	current->o->yeniogrenci(ogrenciler[i]);
    }   
}

void sinif::setogrencic()
{    
    current=head;
    while(current!=NULL)
    {
        current->o->setc();
        current=current->ssinif;
    }
}

void sinif::yazdir()
{
    current=head;
    while(current!=NULL)
    {
        cout<<"Sinif:"<<current->sinifno<<" ("<<current<<")    ";
        current=current->ssinif;
    }
    do{
        devamivarmi=false;
        cout<<endl;
        current=head;
        while(current!=NULL)
        {
            if(current->o->yazdir())
                devamivarmi=true;
            else
                cout<<"            ";
            cout<<"           ";
            current=current->ssinif;
        }
    }
    while(devamivarmi==true);
}

void sinif::ogrencidegistir(char ilkogrenci, char ikinciogrenci)
{
    current=head;
    while(current!=NULL)
    {
        if(ilkogrenci==current->o->ogrencinoal(ilkogrenci))
        {
            currentilko=current;
            current=NULL;
        }
        else
            current=current->ssinif;
    }
    current=head;
    while(current!=NULL)
    {
        if(ikinciogrenci==current->o->ogrencinoal(ikinciogrenci))
        {
            currentikincio=current;
            current=NULL;
        }
        else
            current=current->ssinif;
    }      

    currentilko->o->ogrencidegis(currentikincio->o,ilkogrenci,ikinciogrenci);
    
}

void sinif::siradegistir(int ilksinif, int ikincisinif)
{
    current=head;
    while(current!=NULL)
    {
        if(current->sinifno==ilksinif)
        {      
            ikincicurrent=current;
            current=NULL;                       
        }
        else
            current=current->ssinif; 
    }
    current=head;
    while(current!=NULL)
    {
        if(current->sinifno==ikincisinif)
        {      
            temp=current;
            current=NULL;
        }
        else
            current=current->ssinif; 
    }        
    current=ikincicurrent->osinif;
    ikincicurrent->osinif=temp->osinif;
    if(ikincicurrent->osinif!=NULL)
        ikincicurrent->osinif->ssinif=ikincicurrent;
    else
        head=ikincicurrent; 
    
    temp->osinif=current;    
    if(current!=NULL)
        temp->osinif->ssinif=temp;
    else
        head=temp; 
    
    current=ikincicurrent->ssinif; 
    ikincicurrent->ssinif=temp->ssinif; 
    if(ikincicurrent->ssinif!=NULL)
        ikincicurrent->ssinif->osinif=ikincicurrent;       
    temp->ssinif=current;
    if(current!=NULL)
        temp->ssinif->osinif=temp;   
   
}

sinif::~sinif()
{
    current=head;
    while(current->ssinif!=NULL)
    {        
        current=current->ssinif;
    }
    tail=current;
    while(tail!=NULL)
    {
        current=tail;
        current->o->~ogrenci();
        tail=tail->osinif;
        delete(current);
    }
}
