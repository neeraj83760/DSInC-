#include <iostream>
using namespace std;

struct Node
{

    int key;
    Node *link = NULL;
};

Node *front = NULL, *currPtr, *newNode, *rear= NULL;

class Queue
{
public:
    void enqueue(int key)
    {
        newNode = new Node();
        newNode->key = key; 

        if (front == NULL)
        {
            front = newNode;
            rear = front;

        }
        else
        {
            currPtr = front;
            while (currPtr->link != NULL)
                currPtr = currPtr->link;

            currPtr->link = newNode;
            rear = currPtr->link;
        }

    }

    void dequeue()
    {   
        currPtr = front;
        front = front->link;
        delete(currPtr);

        if (rear == front)
            std::cout << "Last element in the Queue!!"<<endl;
    }

    void peek(){

    std::cout<<"front pointer pointing to element is: "<< front->key<<endl;
    std::cout<<"rear pointer pointing to element is: "<< rear->key<<endl;
     
    }
};


int main(){

Queue s1;

s1.enqueue(23);
s1.enqueue(14);
s1.enqueue(4);
s1.enqueue(12);
s1.enqueue(9);


s1.dequeue();
s1.dequeue();


s1.peek();


}