#ifndef STACK_H
#define STACK_H
class Stack
{   
private:
    int* sayilar;
    int top;
    int gecicitop;
    int reserved;
public:    
    Stack(unsigned int Size=20);
    ~Stack();
    void push(int deger);
    void grow(unsigned int Size=20);
    int peek();
    void yazdir();    
};


#endif /* STACK_H */

