#include <iostream>
using namespace std;

struct Doublylinklist{

    Doublylinklist *prev = NULL; 
    int node;
    Doublylinklist *next = NULL; 
    
};

Doublylinklist *head= NULL, *newNode, *traversePointer, *revPointer;

void insertInLinklist(){

 for (int i = 0; i < 5; i++)
    {

    newNode = new Doublylinklist;      
    
    if(head == NULL){
     
     head = newNode;
     std::cin>> newNode->node;
     traversePointer = head; 
     
    }
    else{
        std::cin>> newNode->node;
        traversePointer->next = newNode;
        newNode->prev = traversePointer;
        traversePointer = traversePointer->next; 
        } 
     

    }

}

void print(){

     traversePointer = head; 
    
    while (traversePointer!=NULL)
    {   
        std::cout<<"The next node address is :" << traversePointer->next <<endl; 
        std::cout<< traversePointer->node <<endl;
        std::cout<<"The prev node address is :" << traversePointer->prev <<endl; 

        
        revPointer = traversePointer;
        traversePointer = traversePointer->next;  
    }
}

void revLinklist(){

     traversePointer = revPointer; 
    
    while (traversePointer!=NULL)

   {   
    
    std::cout<<"After reversing a linklist"<<endl; 
    std::cout<<"The prev node address is :" << traversePointer->prev <<endl; 
    std::cout<< traversePointer->node <<endl;
        
    traversePointer = traversePointer->prev;  
    }
}


int main(){
   
    insertInLinklist(); 
   
    print();

    revLinklist();  

    return 0;    

}


