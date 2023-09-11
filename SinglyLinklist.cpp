#include <iostream>
using namespace std;

struct linklist{

    int node;
    linklist *next = NULL; 
    
};

int main(){

    linklist *head= NULL, *newNode, *traversePointer;

    for (int i = 0; i < 5; i++)
    {

    newNode = new linklist;      
    
    if(head == NULL){
     
     head = newNode;
     std::cin>> newNode->node;
     traversePointer = head; 
     
    }
    else{
        std::cin>> newNode->node;
        traversePointer->next = newNode;
        traversePointer = traversePointer->next; 
        } 
     

    }
    
    traversePointer = head; 
    
    while (traversePointer!=NULL)
    {   
        std::cout<<"The next node address is :" << traversePointer->next <<endl; 
        std::cout<< traversePointer->node <<endl;
        
        traversePointer = traversePointer->next;  
    }
    

    return 0;    

}