#include <iostream>
using namespace std;

int main(){
    // Biggest UNsigned int number is : 4294967295
    // Biggest signed int number is : 2147483647
    // https://www.rapidtables.com/convert/number/binary-to-decimal.html

    int a;
    char b;
    float c; 
    unsigned int e = 4294967297; 
    std::cout<< "Enter the number!" <<endl; 
    std::cout <<"Entered number is :" << sizeof(a) <<endl;
    std::cout <<"Entered number is :" << sizeof(b) <<endl;
    std::cout <<"Entered number is :" << sizeof(c) <<endl;
    std::cout <<"Entered number is :" << sizeof(e) <<endl;
   
    std::cout <<"Entered number is :" << e <<endl;

    

    return 0; 
}

