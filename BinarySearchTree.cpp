#include <iostream>
using namespace std;

struct BST
{
    int node;
    BST *Lchild = nullptr;
    BST *Rchild = nullptr;
};

BST *root = NULL, *newNode, *traversePointer;

BST *insertElement()
{

    for (int i = 0; i < 7; i++)
    {

        newNode = new BST;
        std::cin >> newNode->node;

        if (root == NULL)
        {
            root = newNode;
            std::cout << "The left of Root element :" << root->Lchild << endl;
            std::cout << "The element sucessfully Inserted as a Root element :" << newNode->node << endl;
            std::cout << "The right Root element :" << root->Rchild << endl;
        }

        else
        {
            traversePointer = root;
            while (true)
            {
                if (newNode->node > traversePointer->node)
                {
                    if (traversePointer->Rchild == nullptr)
                    {
                        traversePointer->Rchild = newNode;
                        std::cout << "The left of previous element :" << traversePointer->Lchild << endl;
                        std::cout << "The element sucessfully Inserted as a Right Child :" << newNode->node << endl;
                        std::cout << "The right of the previous element :" << traversePointer->Rchild << endl;
                        break;
                    }

                    traversePointer = traversePointer->Rchild;
                }

                else
                {
                    if (traversePointer->Lchild == nullptr)
                    {
                        traversePointer->Lchild = newNode;
                        std::cout << "The left of previous element :" << traversePointer->Lchild << endl;
                        std::cout << "The element sucessfully Inserted as a left Child :" << newNode->node << endl;
                        std::cout << "The right of previous element :" << traversePointer->Rchild << endl;
                        break;
                    }
                    traversePointer = traversePointer->Lchild;
                }
            }
        }
    }

    return root;
}

void InorderTraversal(BST *ptr)
{
    // std::cout << "InorderTraversal function called :" << counter++ << endl;
    if (ptr != nullptr)
    {
        InorderTraversal(ptr->Lchild);
        std::cout << ptr->node << " ";
        InorderTraversal(ptr->Rchild);
    }
}

int main()
{
    std::cout << "Insert Elements in the BST Tree" << endl;
    BST *root = insertElement();

    std::cout << "Inorder traversal of BST Tree Is: " << endl;
    InorderTraversal(root);

    return 0;
}

