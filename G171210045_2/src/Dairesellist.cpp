/*         * @file  Dairesellist.cpp  
           * @description Textteki sayilar icin dugumler burada olusuyor.
           * @course  2-B  
           * @assignment  2.ödev   
           * @date  29.11.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */
#include "Dairesellist.h"
#include <string.h>

using namespace std;

Dairesellist::Dairesellist()
{
    head=NULL;
    temp=NULL;
    current=NULL;
    tail=NULL;
}

void Dairesellist::sayiata(string satir)
{
    string gecici;
    for(int i=0;i<satir.length();i++)
    {
        if(satir[i]!=' ')
        {
            gecici+=satir[i];
        }
        else
        {
            yenidugum(stoi(gecici));
            gecici="";            
        }
    }
    yenidugum(stoi(gecici));
    stackeat();
   
}
void Dairesellist::yenidugum(int deger)
{
    d n=new dugum;
    if(head==NULL)
    {                         
        n->dugumno=1;
        head=n;
        temp=n;
        tail=n;
    }
    else
    {   
        n->dugumno=temp->dugumno+1;
        n->odugum=temp;
        temp->sdugum=n;
        temp=n;
        tail=n;
        head->odugum=tail;
        tail->sdugum=head;
    }
    n->sayi=deger;    
    n->s=new Stack();
}

void Dairesellist::yazdir(bool durum)
{
    current=head;
    do
    {
        cout<<current->dugumno<<".Dugum:"<<current->sayi;
        if(durum)
            current->s->yazdir();
        else
            cout<<endl;
        current=current->sdugum;
    }while(current!=head);
}

void Dairesellist::kaydir(bool sagami)
{    
    current=head;
    do{
        if(sagami)
            current->sayi=current->odugum->s->peek();
        else
            current->sayi=current->sdugum->s->peek();
        current=current->sdugum;
    }while(current!=head);
    stackeat();
}

void Dairesellist::dugumdurum(int dugum)
{
    bool varmi=true;
    current=head;
    while(current->dugumno!=dugum)
    {
        current=current->sdugum;
        if(current==head)
        {
            varmi=false;
            break;
        }
    }
    if(varmi)
    {
    cout<<current->dugumno<<".Dugum:"<<current->sayi;
    current->s->yazdir();
    }
    else
        cout<<"Bu numarali bir dugum yok!!"<<endl;
}

void Dairesellist::stackeat()
{
    current=head;
    do{
        current->s->push(current->sayi);
        current=current->sdugum;
    }while(current!=head);
}

Dairesellist::~Dairesellist()
{
    current=tail;
    while(current!=head)
    {
    tail=current;
    current=current->odugum;
    tail->s->~Stack();
    delete(tail);    
    }
}