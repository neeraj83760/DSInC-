#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

/*

Linear Probing: In linear probing, the hash table is searched sequentially that starts from the original location of the hash. If in case the location that we get is already occupied, then we check for the next location.

The function used for rehashing is as follows: rehash(key) = (n+1)%table-size.

Applications of linear probing:

Linear probing is a collision handling technique used in hashing, where the algorithm looks for the next available slot in the hash table to store the collided key. Some of the applications of linear probing include:

Symbol tables: Linear probing is commonly used in symbol tables, which are used in compilers and interpreters to store variables and their associated values. Since symbol tables can grow dynamically, linear probing can be used to handle collisions and ensure that variables are stored efficiently.

Caching: Linear probing can be used in caching systems to store frequently accessed data in memory. When a cache miss occurs, the data can be loaded into the cache using linear probing, and when a collision occurs, the next available slot in the cache can be used to store the data.

Databases: Linear probing can be used in databases to store records and their associated keys. When a collision occurs, linear probing can be used to find the next available slot to store the record.

Compiler design: Linear probing can be used in compiler design to implement symbol tables, error recovery mechanisms, and syntax analysis.

Spell checking: Linear probing can be used in spell-checking software to store the dictionary of words and their associated frequency counts. When a collision occurs, linear probing can be used to store the word in the next available slot.

Overall, linear probing is a simple and efficient method for handling collisions in hash tables, and it can be used in a variety of applications that require efficient storage and retrieval of data.

Challenges in Linear Probing :

Primary Clustering: One of the problems with linear probing is Primary clustering, many consecutive elements form groups and it starts taking time to find a free slot or to search for an element.

Secondary Clustering: Secondary clustering is less severe, two records only have the same collision chain (Probe Sequence) if their initial position is the same.

**************** Diffrence between sperate chaining and open addressing ***********************


S.No.	Separate Chaining	                       Open Addressing
1.	Chaining is Simpler to implement.	           Open Addressing requires more computation.

2.	In chaining, Hash table never fills up,        In open addressing, table may become full.
we can always add more elements to chain .

3.	Chaining is Less sensitive to the hash         Open addressing requires extra care to avoid clustering and load factor.
                                                   function or load factors.

4.	Chaining is mostly used when it is unknown      Open addressing is used when the frequencyandnumber of keys known.
how many and how frequently keys may be inserted
or deleted.


5.	Cache performance of chaining is not good as    Open addressing provides better cache performance as everything s                                                  stored in 
                                                    the same table.
keys are stored using linked list.	


6.	Wastage of Space (Some Parts of hash table      In Open addressing a slot can be used even if an inputdoesn't d                                                   map to it.
in chaining are never used).	

7.	Chaining uses extra space for links.	        No links in Open addressing



Note: Cache performance of chaining is not good because when we traverse a Linked List, we are basically jumping from one node to another, all across the computer’s memory. For this reason, the CPU cannot cache the nodes which aren’t visited yet, this doesn’t help us. But with Open Addressing, data isn’t spread, so if the CPU detects that a segment of memory is constantly being accessed, it gets cached for quick access.

Performance of Open Addressing:
Like Chaining, the performance of hashing can be evaluated under the assumption that each key is equally likely to be hashed to any slot of the table (simple uniform hashing)

m = Number of slots in the hash table

n = Number of keys to be inserted in the hash table

 Load factor α = n/m  ( < 1 )

Expected time to search/insert/delete < 1/(1 – α)

So Search, Insert and Delete take (1/(1 – α)) time

*/

// Very basic hash function
int HashFunction(int key, int table_Size)
{

    return key % table_Size;
}

class Hashtable
{

private:
    static const int table_Size = 8;
    std::vector<int> table[table_Size];

public:
    void insertKey(int key);
    bool search(int key);
    void delKey(int key);
    void display();
};

void Hashtable::insertKey(int key)
{

    int index = HashFunction(key, table_Size);

    // Linear probing

    while (!table[index].empty())
    {

        index = (index + 1) % table_Size;
    }

    table[index].push_back(key);
}

bool Hashtable::search(int key)
{

    int index = HashFunction(key, table_Size);

    while (!table[index].empty())
    {

        for (int value : table[index])
        {

            if (value == key)
                return true;
        }

        index = (index + 1) % table_Size;
    }

    return false;
}

void Hashtable:: delKey(int key)
{

    int index = HashFunction(key, table_Size);

    while (!table[index].empty()){

    for (auto it = table[index].begin(); it != table[index].end(); ++it)
    {

        if (*it == key)
        {
            table[index].erase(it);
            return; // key found and removed
        }
    }

            index = (index + 1) % table_Size;

    }
}

void Hashtable::display(){

        for (int i = 0; i < table_Size; ++i) {
            std::cout << "[" << i << "]: ";
            for (int value : table[i]) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    
}


int main() {
    
    Hashtable hashTable;
    
    hashTable.insertKey(10);
    hashTable.insertKey(20);
    hashTable.insertKey(30);
    hashTable.insertKey(11);

    std::cout << "Hash Table Contents:" << std::endl;
    hashTable.display();

    int searchKey = 20;
    if (hashTable.search(searchKey)) {
        std::cout << "Key " << searchKey << " found in the hash table." << std::endl;
    } else {
        std::cout << "Key " << searchKey << " not found in the hash table." << std::endl;
    }

    int removeKey = 30;
    hashTable.delKey(removeKey);
    std::cout << "Removed key " << removeKey << " from the hash table." << std::endl;

    std::cout << "Updated Hash Table Contents:" << std::endl;
    hashTable.display();

    return 0;
}

