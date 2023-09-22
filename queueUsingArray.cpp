#include <iostream>
using namespace std;

class queue{
    
    private:
    static const int Max_length = 6; 
    int queue[Max_length], front =0, rear=0; 
    public:
    
    void front(){
    if(front > rear) std::cout<<"Queue is Empty!!"<<endl;

    queue[front] = 0;
    front++;  

    }

    void rear(int key){
    
    queue[rear] = key;
    rear++;

    }

    void QueueStat(){

        std::cout<<"The front pointer pointing to element:"<<queue[front]<<endl;
        std::cout<<"The rear pointer pointing to element:"<<queue[rear]<<endl;
    }
};

int main(){

    queue q1;
    q1.rear(13);


}