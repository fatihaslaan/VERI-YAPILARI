/*         * @file  Okul.cpp  
           * @description sınıfımıza bu kısımdan ulaşabiliyoruz.
           * @course  2-B  
           * @assignment  1.ödev   
           * @date  27.10.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */ 
#include "Okul.h"

using namespace std;

okul::okul()
{
     okulnode=new sinif();
}

okul::~okul()
{
    okulnode->~sinif();
}

void okul::ogrencidegistir(char ilkogrenci,char ikinciogrenci)
{
    okulnode->ogrencidegistir(ilkogrenci,ikinciogrenci);
}

void okul::yenisinif(int sinifno)
{   
   okulnode->yenisinif(sinifno);  
}
void okul::yeniogrenci(string ogrenciler)
{
    okulnode->yeniogrenci(ogrenciler);
}
void okul::yazdir()
{
    okulnode->yazdir();
}

void okul::sinifdegistir(int ilksinif,int ikincisinif)
{
    okulnode->siradegistir(ilksinif,ikincisinif);
}

void okul::set()
{
    okulnode->setogrencic();
}

