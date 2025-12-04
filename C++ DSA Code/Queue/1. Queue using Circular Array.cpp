// Queue using circular array (better approach)
#include<iostream>
using namespace std;

class Queue
{
    int front = -1, rear = -1, capacity, *array = nullptr;
    public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        array = new int[capacity];
    }
    
    bool isEmpty()
    {
        if(front == -1)
        {
            return true;
        }
        else 
        {
            return false;
        }
    } 
    
    void enQueue(int data)
    {
        if(front == -1)
        {
            array[++front] = data;
            rear++;
        }
        else if((rear + 1) % capacity != front)
        {
            rear = (rear + 1) % capacity;
            array[rear] = data;
        }
        else
        {
            cout<<"Queue is Already Full!" <<endl;
        }
    } 
    
    int deQueue()
    {
        if(front != -1)
        {
            if(front == rear)
            {
                int tempIndex = front;
                front = rear = -1;
                return array[tempIndex];
            }
            else
            {
                return array[front++];
            }
        }
        else
        {
            cout<<"Queue is Already Empty!";
            return -1;
        }
    }     
    
    
   
    void show()
    {
        cout<<"Queue: ";
        if(front != -1)
        {
            int tempFront = front;
            while(tempFront != rear)
            {
                cout<<array[tempFront] <<"  ";
                tempFront = (tempFront + 1) % capacity;
            }
            cout<<array[tempFront];
        }
        cout<<endl;
    }
    
    int getFront()
    {
        if(front != -1)
        {
            return array[front];
        }
        else
        {
            return -1;
        }
    }
    
    int getRear()
    {
        if(rear != -1)
        {
            return array[rear];
        }
        else
        {
            return -1;
        }
    }
    
    void deleteQueue()
    {
        if(array != nullptr)
        {
          delete []array;
          array = nullptr;
          front = rear = -1;
        }
    }
    
    ~Queue()
    {
        deleteQueue();
    }

};

int main()
{
    Queue q(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.show();
    
    q.enQueue(60);
    
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.show();
    
    cout<<"Front: " <<q.getFront() <<endl;
    cout<<"Rear: " <<q.getRear() <<endl;
    
    q.deleteQueue();
    q.show();

    return 0;
}