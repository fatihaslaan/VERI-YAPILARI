/*         * @file  Yonetim.cpp  
           * @description Ara islemler icin.
           * @course  2-B  
           * @assignment  2.ödev   
           * @date  29.11.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */
#include <fstream>
#include <string>
#include <string.h>
#include "Yonetim.h"
#include "Dairesellist.h"

ifstream dosyaoku;
Dairesellist *d=new Dairesellist();

Yonetim::Yonetim(string text)
{
    dosyaoku.open(text);
    sayilariata();
}

void Yonetim::sayilariata()
{       
    getline(dosyaoku, satir);
    d->sayiata(satir);    
}

void Yonetim::yaz()
{
    int secim;
    d->yazdir(false);
    while(secim!=5)
    {
        cout<<endl<<endl<<endl<<"1.Sola Hareket"<<endl;
        cout<<"2.Saga Hareket"<<endl;
        cout<<"3.Bir Dugumun Durumlarini Yazdir"<<endl;
        cout<<"4.Tum Dugumleri Yazdir"<<endl;
        cout<<"5.Cikis"<<endl<<"=>";        
        cin>>secim;
        cout<<endl;
        switch(secim)
        {
            case 1:
            {
                system("cls");
                d->kaydir(false);
                d->yazdir(false);               
                break;
            }
            case 2:
            {
                system("cls");
                d->kaydir(true);
                d->yazdir(false);                
                break;
            }
            case 3:
            { 
                int dugum;
                cout<<"Hangi Dugumun Durumunu Gormek Istersiniz?"<<endl<<"=>";
                cin>>dugum;
                system("cls");
                d->dugumdurum(dugum);
                break;
            }
            case 4:
            {                
                system("cls");
                d->yazdir(true);
                break;
            }
            case 5:
            {
                d->~Dairesellist();
                break;
            }
            default:
            {
                system("cls");
                cout<<"HATA!!!";                
            }
        }
    }   
}
