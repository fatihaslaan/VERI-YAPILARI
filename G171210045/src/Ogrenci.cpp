/*         * @file  Ogrenci.cpp  
           * @description yeni ogrenci eklemeye ve sırasını değiştirmeye yarıyor.
           * @course  2-B  
           * @assignment  1.ödev   
           * @date  27.10.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */ 
#include <cstddef>
#include "Ogrenci.h"

using namespace std;

ogrenci::ogrenci()
{
    h=NULL;
    tmp=NULL;
    c=NULL;
    ikincic=NULL;
    ucuncuc=NULL;    
}

void ogrenci::setc()
{
    c=h;
}

void ogrenci::yeniogrenci(char ogrencino)
{
    onode n=new ogrencinode;
    n->sogrenci=NULL;
    if(h==NULL){
        h=n;
        tmp=n;
        h->oogrenci=NULL;
        c=n;
    }
    else
    {        
        n->oogrenci=tmp;
        tmp->sogrenci=n;
        tmp=n;
    }
    n->ogrencino=ogrencino;     
}

bool ogrenci::yazdir()
{    
    if(c!=NULL)
    {
        cout<<c->ogrencino<<" ("<<c<<")";
        c=c->sogrenci;
        return true;          
    }
}

char ogrenci::ogrencinoal(char ilkogrenci)
{    
    c=h;
    while(c!=NULL)
    {
        if(c->ogrencino==ilkogrenci)
        {        
            return c->ogrencino;            
        }
        else
            c=c->sogrenci;       
    }
    return ' ';
}

void ogrenci::ogrencidegis(ogrenci *ikinciogrenci,char ilkogrenci,char ikinciogrencic)
{    
    c=h;
    while(c!=NULL)
    {
        if(c->ogrencino==ilkogrenci)
        {      
            ilkc=c; 
            c=NULL;            
        }
        else
            c=c->sogrenci;       
    }
    ikinciogrenci->c=ikinciogrenci->h;
    while(ikinciogrenci->c!=NULL)
    {
        if(ikinciogrenci->c->ogrencino==ikinciogrencic)
        {   
            ikinciogrenci->ikincic=ikinciogrenci->c;
            ikinciogrenci->c=NULL;            
        }
        else
            ikinciogrenci->c=ikinciogrenci->c->sogrenci;       
    }   
    ikinciogrenci->c=ikinciogrenci->ikincic;
    ikinciogrenci->ucuncuc=ikinciogrenci->ikincic;
    c=ilkc;
     
    
    tmp=c->oogrenci;    
    c->oogrenci=ikinciogrenci->ikincic->oogrenci;
    if(c->oogrenci!=NULL)
        c->oogrenci->sogrenci=c;
    else
        ikinciogrenci->h=c;
    
    ikinciogrenci->ucuncuc->oogrenci=tmp;    
    if(tmp!=NULL)
        ikinciogrenci->ucuncuc->oogrenci->sogrenci=ikinciogrenci->ucuncuc;
    else
        h=ikinciogrenci->ikincic; 
    
    tmp=c->sogrenci;
    c->sogrenci=ikinciogrenci->ikincic->sogrenci; 
    if(c->sogrenci!=NULL)
        c->sogrenci->oogrenci=c;       
    ikinciogrenci->ucuncuc->sogrenci=tmp;
    if(tmp!=NULL)
        ikinciogrenci->ucuncuc->sogrenci->oogrenci=ikinciogrenci->ucuncuc;         
}

ogrenci::~ogrenci()
{
    c=h;
    while(c->sogrenci!=NULL)
    {        
        c=c->sogrenci;
    }
    tl=c;
    while(tl!=NULL)
    {
        c=tl;
        tl=tl->oogrenci;
        delete(c);
    }    
}

