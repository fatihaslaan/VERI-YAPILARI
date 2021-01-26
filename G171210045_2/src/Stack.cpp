/*         * @file  Stack.cpp  
           * @description Dugumlerdeki degisiklikleri burada kaydediyoruz.
           * @course  2-B  
           * @assignment  2.ödev   
           * @date  29.11.2018  
           * @author  fatih aslan email:fatih.aslan9@ogr.sakarya.edu.tr   */
#include <iostream>
#include <iomanip>
#include "Stack.h"
using namespace std;
Stack::Stack(unsigned int Size)
{
    reserved=Size;
    top=0;
    sayilar=new int[Size];
}

void Stack::push(int deger)
{
    if(top==20)
        grow();
    sayilar[top]=deger;
    top++;  
}

void Stack::grow(unsigned int Size)
{
    int *gecicisayilar=new int [reserved+Size];
    for(int i=0;i<reserved;i++)
    {
        gecicisayilar[i]=sayilar[i];
    }
    delete [] sayilar;
    sayilar=gecicisayilar;
    reserved+=Size;
}

int Stack::peek()
{
    return sayilar[top-1];
}

void Stack::yazdir()
{
    cout<<setw(10-to_string(sayilar[top-1]).length())<<":";
    for(gecicitop=top-1;gecicitop>=0;gecicitop--)
    {
        cout<<setw(5)<<sayilar[gecicitop];
    }
    cout<<endl;
}

Stack::~Stack()
{
    delete [] sayilar;
    top=0;
    reserved=0;
}