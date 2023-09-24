#include<iostream>
#include <list>
#include<vector>
#include<algorithm>
using namespace std; 

// Before implemeting hashtables lets understand some basic concepts 
//  What is list in C++  : It is implemented as a doubly linked list, which means that each element in the list contains a value and two pointers (references) to the previous and next elements in the list. Lists are part of the C++ Standard Template Library (STL) and are defined in the <list> header.

int main()
{

std::list<int> myList;

myList.push_back(12);
myList.push_back(1);
myList.push_back(7); 
myList.push_back(9); 
myList.push_back(11); 
myList.push_back(89); 
myList.push_back(4);  

/*

Lists do not provide direct access to elements by index like arrays or vectors. To access elements, you can use iterators. An iterator is an object that points to an element in the list:

Iterating Through a List:
To traverse all elements in a list, you can use a for loop with iterators or a range-based for loop introduced in C++11:

*/ 

std::list<int>::iterator it = myList.begin();

int firstElement = *it;
it++;
int secondElement = *it;

std::cout<<firstElement <<endl;
std::cout<<secondElement <<endl;

// auto : 
for (auto it = myList.begin(); it != myList.end(); ++it) {

    std::cout<<*it<<endl; 
    
}

/* What is Vector in C++ :   vector is a dynamic array that provides a flexible and efficient way to store and manipulate collections of elements. It is part of the C++ Standard Library and is defined in the <vector> header.

Here's a breakdown of what a vector is and how it works:

1. Dynamic Array: A vector is implemented as a dynamic array, which means it can grow or shrink in size at runtime. Unlike regular arrays in C++ with a fixed size, vectors can change their size as needed.

2. Template Class: Vectors are template classes, which means they can store elements of any data type (e.g., integers, floating-point numbers, objects, etc.). You define the data type when you declare a vector.

3. Dynamic Sizing: Vectors automatically manage memory for you. When you add elements beyond the vector's current capacity, it dynamically allocates more memory to accommodate the new elements. This resizing process is transparent to the user.

4. Random Access: Vectors support fast random access to elements. You can access elements by their index in constant time (O(1)). 

5. Size and Capacity: Vectors have the size() method to get the number of elements currently stored in the vector and the capacity() method to get the total number of elements it can hold without resizing. The capacity is greater than or equal to the size.

6. Standard Library Functions: Vectors come with a variety of useful member functions and algorithms to perform operations such as inserting, deleting, sorting, searching, and more.

7. Efficient Iteration: You can iterate through the elements of a vector using iterators or range-based for loops, making it easy to process all elements.

*/ 

std::vector<int> myVector; 

myVector.push_back(12);
myVector.push_back(10);
myVector.push_back(2);
myVector.push_back(6);
myVector.push_back(7);
myVector.push_back(9);
myVector.push_back(19);

std::cout<<"myVector is element is : "<< myVector[0]<<endl;
std::cout<<"myVector is element is : "<< myVector[1]<<endl;

std::sort(myVector.begin(), myVector.end());

// std::find(myVector.begin(), myVector.end(), 6);  


for(int i : myVector)
{
    std::cout<<i<<endl;    
}

return 0;

}