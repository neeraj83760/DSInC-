#include <iostream>
using namespace std;

/* If you are making a tree and the element u are trying to insert is equal to root element
then either put it in the leftsub tree or right sub tree.
*/

struct BST
{

    BST *Lchild = NULL;
    int node;
    BST *Rchild = NULL;
};

BST *root = NULL, *newNode, *traversePointer,*curr;

void insertElement()
{

    for (int i = 0; i < 6; i++)
    {

        newNode = new BST;
        std::cin >> newNode->node;

        if (root == NULL) 
        {
        root = newNode;
        std::cout<< "The left of Root element :" << root->Lchild <<endl;
        std::cout<< "The element sucessfully Inserted as a Root element :" << newNode->node <<endl;
        std::cout<< "The right Root element :" << root->Rchild <<endl;
        }    
        
        else{
        traversePointer = root;  
            while (true)
            {
                if (newNode->node > traversePointer->node)
                {
                    if (traversePointer->Rchild == NULL)
                    {
                        traversePointer->Rchild = newNode;
                        std::cout<< "The left of Right child element :" << traversePointer->Lchild <<endl;
                        std::cout<< "The element sucessfully Inserted as a Right Child :" << newNode->node <<endl;
                        std::cout<< "The right of Right child element :" << traversePointer->Rchild <<endl;
                        break;
                    }

                    traversePointer = traversePointer->Rchild;
                }

                else
                {
                    if (traversePointer->Lchild == NULL)
                    {
                       traversePointer->Lchild = newNode;
                       std::cout<< "The left of left child element :" << traversePointer->Lchild <<endl;
                       std::cout<< "The element sucessfully Inserted as a left Child :" << newNode->node <<endl;
                       std::cout<< "The right of left child element :" << traversePointer->Rchild <<endl;
                       break;
                    }
                    traversePointer = traversePointer->Lchild;
                }
            }
        }
   }   
}


void InorderTraversal(BST *ptr)
{
    if(ptr == NULL) return;
    InorderTraversal(ptr->Lchild);
    std::cout << ptr->node <<endl;
    InorderTraversal(ptr->Lchild);
    
}

int main()
{   
    std::cout << "Insert Elements in the BST Tree"<<endl;
    insertElement();

    curr = root;
    std::cout << "Inorder traversal of BST Tree Is: "<<endl;
    InorderTraversal(curr);

    return 0;
}