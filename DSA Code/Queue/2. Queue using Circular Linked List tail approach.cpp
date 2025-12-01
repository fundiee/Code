// Queue using Circular Linked List tail approach
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Queue
{
    Node *tail = nullptr;
    public:
    Queue()
    { }
    
    bool isEmpty()
    {
        if(tail == nullptr)
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
        if(tail == nullptr)
        {
            tail = new Node(data);
            tail->next = tail;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = tail->next;
            tail->next = temp;
            tail = temp;
        }
    }
    
    void deQueue()
    {
        if(tail != nullptr)
        {
            if(tail->next == tail)
            {
                delete tail;
                tail = nullptr;
            }
            else
            {
                Node *temp = tail->next;
                tail->next = tail->next->next;
                delete temp;
            }
        }
        else
        {
            cout<<"Queue is already empty!" <<endl;
        }
    }
    
    int getFront()
    {
        if(tail != nullptr)
        {
            return tail->next->data;
        }
        else
        {
            return -1;
        }
    }
    
    int getRear()
    {
        if(tail != nullptr)
        {
            return tail->data;
        }
        else
        {
            return -1;
        }
    }

    void showQueue()
    {
        cout<<"Queue: ";
        if(tail != nullptr)
        {
            Node *temp = tail->next;
            while(temp != tail)
            {
                cout<<temp->data <<"  ";
                temp = temp->next;
            }
            cout<<temp->data;
        }
        cout<<endl <<"----------------------------------------" <<endl;
    }
    
    void deleteQueue()
    {
        if(tail != nullptr)
        {
            Node *temp = tail->next;
            while(temp != tail)
            {
                Node *delNode = temp;
                temp = temp->next;
                delete delNode;
            }
            delete tail;
            tail = nullptr;
        }
    }
    
    ~Queue()
    {
        deleteQueue();
    }
};


int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.showQueue();
    
    if(q.isEmpty())
    {
        cout<<"Queue is Empty!" <<endl;
    }
    else
    {    
        cout<<"Queue is not Empty!" <<endl;
    }
    
    cout<<"Front: " <<q.getFront() <<endl;
    cout<<"Rear: " <<q.getRear() <<endl;
    cout<<"----------------------------------------" <<endl;
    
    q.deQueue();
    q.deQueue();
    q.showQueue();
    
    q.deleteQueue();
    q.showQueue();
    
    return 0;
}