#include <iostream>
using namespace std;

struct BST{

    BST *Lchild = NULL; 
    int node;
    BST *Rchild = NULL; 
    
};

BST *root= NULL, *newNode, *traversePointer;

void insert(){

for (int i = 0; i < 10; i++)
    {

    newNode = new BST;    

if(root == NULL){

     root = newNode;
     std::cin>> newNode->node;
     traversePointer = root; 
}

else{
    
    if(newNode->node > root->node){
    
    traversePointer->Rchild = newNode; 

    }

    else{

    traversePointer->Lchild = newNode;

    }

    }

}
}