/*         * @file  Yonetim.cpp  
           * @description Ara işlemler için.
           * @course  2-B  
           * @assignment  3.ödev   
           * @date  16.12.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */
#include "Yonetim.h"
#include "Agaclar.h"
#include <iostream>
using namespace std;


Yonetim::Yonetim()
{
    cout<<"Agaclar icin deger girin:";
    cin>>deger;
    cout<<endl;    
    char gecici;    
}

void Yonetim::yaz()
{
    Agaclar *a=new Agaclar(deger);    
    int secim;
    while(secim!=4)
    {
        cout<<endl<<endl<<endl<<"1.Max Degerleri Cikar"<<endl;
        cout<<"2.Min Degerleri Cikar"<<endl;
        cout<<"3.Level Order Yazdir"<<endl;
        cout<<"4.Cikis"<<endl;        
        cin>>secim;
        cout<<endl;
        switch(secim)
        {
            case 1:
            {
                system("cls");
                a->maxyaz();
                break;
            }
            case 2:
            {
                system("cls");
                a->minyaz();
                break;
            }
            case 3:
            { 
                system("cls");
                a->levelorderyazdir();
                break;
            }
            case 4:
            {
                a->~Agaclar();
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
