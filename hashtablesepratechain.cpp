#include<iostream>
#include <list>
#include<vector>
#include<algorithm>
using namespace std; 

//Very basic hash function  
int HashFunction(int key , int table_Size){

return key % table_Size; 

}

class Hashtable{
   
   private:
   int table_Size;
   std::vector<std::list<std::pair<int, int>>> table;

   public:
   Hashtable(int size) : table_Size(size), table(size) {} // Constructor to initialize table_Size
   std::vector<int> myHashTable;  
   void insertKey(int key , int value);
   bool get(int key, int &value);
   void delKey(int key);

};

void Hashtable::insertKey(int key, int value){

int index = HashFunction(key, table_Size);
table[index].push_back(std::make_pair(key,value));  

}

bool Hashtable::get(int key, int &value){

int index = HashFunction(key, table_Size);

for (const auto &pair: table[index])
{

if(pair.first == key)
{
value = pair.second;
return true; // key found
}

return false; // key not found  
}


}

void Hashtable::delKey(int key){

int index = HashFunction(key, table_Size);

for(auto it = table[index].begin(); it != table[index].end(); ++it){

if (it->first == key)
{
   table[index].erase(it);
   return; // key found and removed  
}

}


} 

int main()
{
 
Hashtable myHashtable(8); 

myHashtable.insertKey(1,44);
myHashtable.insertKey(2,25);

int val; 

if(myHashtable.get(2,val)) std::cout<<"The value associate with key 2 is: "<<val<<endl;

else  std::cout<<"key 2 not found : "<<val<<endl;


return 0; 
}


