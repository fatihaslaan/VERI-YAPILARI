/*         * @file  Yonetim.cpp  
           * @description programda gerekli olan bazı şeyleri çalıştırıyor.
           * @course  2-B  
           * @assignment  1.ödev   
           * @date  27.10.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */ 
#include <fstream>
#include <string.h>
#include "Okul.h"
#include "Yonetim.h"

ifstream dosyaoku;
okul *o=new okul();
yonetim::yonetim(string text)
{
    dosyaoku.open(text);
}

void yonetim::ogrencileri_ve_siniflari_ata()
{   
    while (dosyaoku.good())
    {
	getline(dosyaoku, satir);
        o->yenisinif(stoi(satir.substr(0,1)));
	satir = satir.substr(2, satir.length());		
        o->yeniogrenci(satir); 
    }       
}

void yonetim::yaz()
{
    int secim;
    int sinifbir;
    int sinifiki;
    char ogrencibir;
    char ogrenciiki;
    while(secim!=3)
    {
        o->set();
        o->yazdir();
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"1.Sinif Degistir"<<endl;
        cout<<"2.Ogrenci Degistir"<<endl;
        cout<<"3.Cikis"<<endl;
        cout<<"=>";
        cin>>secim;
        cout<<endl;
        switch(secim)
        {
            case 1:
            {
                cout<<"1.Sinif:";
                cin>>sinifbir;
                cout<<"2.Sinif:";
                cin>>sinifiki;
                o->sinifdegistir(sinifbir,sinifiki);
                system("cls");
                break;
            }
            case 2:
            {
                cout<<"1.Ogrenci:";
                cin>>ogrencibir;
                cout<<"2.ogrenci:";
                cin>>ogrenciiki;
                o->ogrencidegistir(ogrencibir,ogrenciiki);
                system("cls");
                break;
            }
            case 3:
            {
                o->~okul();
                break;
            }
            default:
                cout<<"hatalisecim"; 
        }
    }  
   
}
