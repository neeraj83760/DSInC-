#include <iostream>
using namespace std;

class queue{
    
    private:
    static const int Max_length = 6;
    int queue[Max_length], front =0, rear=0;
    public:
    
    void dequeue(){
    if(front > rear) std::cout<<"Queue is Empty!!"<<endl;
    
    queue[front] = 0;
    front++;
     
    }

    void enqueue(int key){
    
    queue[++rear] = key;

    }

    void QueueStat(){

        std::cout<<"The front pointer pointing to element:"<<queue[front]<<endl;
        std::cout<<"The rear pointer pointing to element:"<<queue[rear]<<endl;
        
    }
};

int main(){

    queue q1;

    // q1.QueueStat();

    q1.enqueue(2);
    q1.enqueue(11);
    q1.enqueue(4);
    q1.enqueue(7);
    q1.enqueue(89);
   
    q1.dequeue();
     
    q1.QueueStat(); 

}