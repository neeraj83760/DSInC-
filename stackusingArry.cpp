#include <iostream>
using namespace std;

class stack{

    private:
    static const int Max_Size=10; 
    int stack[Max_Size-1];
    int top=-1; 

    public:
    void push(int key){
    
    if(top == Max_Size-1) std::cout<<"Stack is full !";
    else
    {    
    stack[++top] = key;
    std::cout<<"Top on the stack is:"<<stack[top]<<endl;
    std::cout<<"Index of the element is:"<<top<<endl;    
    }
    }

    void pop(){
    
    top--;
    if(top == -1) is_empty();

    std::cout<<"Top on the stack is:"<<stack[top]<<endl;    
 

    }

    void Peek(){

        if(top>=0)
        {
        std::cout<<"Top on the stack is:"<<stack[top]<<endl;
        std::cout<<"Index of the element is:"<<top<<endl;
        } 
    }

    bool is_empty(){
    
    if(top==-1) std::cout<<"Stack is Empty!!"<<endl; 

    }

};

int main(){

// Created an object from the stack class 
stack StackInstance; 

StackInstance.push(13);
StackInstance.push(12);
StackInstance.push(2);
StackInstance.push(7);
StackInstance.push(20);
StackInstance.push(5);

StackInstance.pop(); 
StackInstance.pop(); 

StackInstance.Peek(); 


}