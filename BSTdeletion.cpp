#include <iostream>
using namespace std; 

struct BST{

    BST *Lchild = NULL;
    int val;
    BST *Rchild = NULL;
};

BST *root=NULL , *traversePointer, *newNode;

BST* insert(){

for (int i = 0; i < 6; i++)
{

newNode = new BST; 
std::cin>> newNode->val;

if(root== NULL)  
{
   root = newNode; 
}

else{

    traversePointer =root; 
    while (true)
    {
        if(newNode->val > traversePointer->val)
        {
        
        if(traversePointer->Rchild == NULL)
        {
        traversePointer->Rchild = newNode;
        break;
        }
        traversePointer = traversePointer->Rchild;
        }
        else{

            if(traversePointer->Lchild == NULL)  
            {
                traversePointer->Lchild = newNode;
                break; 
            }
            traversePointer = traversePointer->Lchild; 
        } 
    }
    
}

}

return root; 

}

void DeleteElement(BST *root, int key){

// The node which u deleting has no child, Leaf node deletion 


// The node which u are deleting has one child, attach its child with its grandparent 

// The node which u are deleting has two child, the node which u are deleting pick the biggest element in its left subtree and put it at a place from where u are deleting the element, OR pick the smallest element in its right subtree and put it at a place from where u are deleting the element 

// Speical case in deletion : suppose u are trying to delete an element having two child and u picked the smallest element from its right subtree but the element u picked has a one right child, in that case u just need to put the smallest element in the place from u are deleting element and attach smallest element child to its granparent. Example of tree given below
/*

           25
          / 
        10 
       /   \  
      5      20
    /  \     /  \
   3    6   15  21
           /  
         13
          \
           14
*/        

}

void InorderTraversal(BST * root){

if(root != NULL)
{   
    std::cout<<root->val<<" "; 
    InorderTraversal(root->Lchild);
    InorderTraversal(root->Rchild);
}

}


int main(){

    std::cout<<"Insert the number in a TREE"<<endl;
    BST *root = insert();

    std::cout<<"Inserted Tree elements are :"<<endl;
    InorderTraversal(root); 

    return 0;     
 
}


