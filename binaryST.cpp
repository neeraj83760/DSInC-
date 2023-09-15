#include <iostream>
using namespace std;

/*basically the error in your code is in the InorderTraversal function. You’re calling InorderTraversal(ptr->Lchild) twice, which means you’re only traversing the left subtree of your binary search tree (BST). The second call to InorderTraversal(ptr->Lchild) should be InorderTraversal(ptr->Rchild) to traverse the right subtree.
*/

struct BST
{
    int node;
    BST *Lchild = nullptr;
    BST *Rchild = nullptr;
};

BST *root = NULL, *newNode, *traversePointer;

BST *insertElement()
{
    for (int i = 0; i < 6; i++)
    {
        newNode = new BST;
        cin >> newNode->node;

        if (root == NULL)
        {
            root = newNode;
            cout << "The left of Root element :" << root->Lchild << endl;
            cout << "The element sucessfully Inserted as a Root element :" << newNode->node << endl;
            cout << "The right Root element :" << root->Rchild << endl;
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
                        cout << "The left of previous element :" << traversePointer->Lchild << endl;
                        cout << "The element sucessfully Inserted as a Right Child :" << newNode->node << endl;
                        cout << "The right of the previous element :" << traversePointer->Rchild << endl;
                        break;
                    }
                    traversePointer = traversePointer->Rchild;
                }
                else
                {
                    if (traversePointer->Lchild == nullptr)
                    {
                        traversePointer->Lchild = newNode;
                        cout << "The left of previous element :" << traversePointer->Lchild << endl;
                        cout << "The element sucessfully Inserted as a left Child :" << newNode->node << endl;
                        cout << "The right of previous element :" << traversePointer->Rchild << endl;
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
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        InorderTraversal(ptr->Lchild);
        cout << ptr->node << " ";
        InorderTraversal(ptr->Rchild);
    }
}

int main()
{
    cout << "Insert Elements in the BST Tree" << endl;
    BST *root = insertElement();

    cout << "Inorder traversal of BST Tree Is: " << endl;
    InorderTraversal(root);

    return 0;
}