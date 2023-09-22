#include <iostream>
using namespace std;

struct Node
{

    int key;
    Node *link = NULL;
};

Node *root = NULL, *currPtr, *newNode, *top;

class Stack
{
int Stack_Size = 1;

public:
    void push(int key)
    {
        newNode = new Node();
        newNode->key = key; 

        if (Stack_Size == 5)
           {
            std::cout << "Stack is Full !!" << endl;
            return; 
           } 
        if (root == NULL)
        {
            root = newNode;
            top = root;
        }
        else
        {
            currPtr = root;
            while (currPtr->link != NULL)
                currPtr = currPtr->link;

            currPtr->link = newNode;
            top = currPtr->link;
        }

        Stack_Size++;
    }

    void pop()
    {   
        currPtr = root;
        while(currPtr->link->link!= NULL) currPtr = currPtr->link; 
        
        currPtr->link = NULL;
        top = currPtr; 

        if (top == root)
            std::cout << "Last element in the Stack!!"<<endl;
    }

    void peek(){

    std::cout<<"Top of the element is: "<< top->key<<endl; 

    }
};


int main(){

Stack s1;

s1.push(23);
s1.push(14);
s1.push(4);
s1.push(12);
// s1.push(20);
// s1.push(2);

s1.pop();
s1.pop();
// s1.pop();

s1.peek();


}