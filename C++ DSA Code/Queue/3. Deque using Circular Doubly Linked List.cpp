// Deque using Circular Doubly Linked List
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *prev = nullptr, *next = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Deque
{
    Node *head = nullptr;
    public:
    Deque()
    { }
    
    bool isEmpty()
    {
        if(head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }    
    }
    
    void insertAtFront(int data)
    {
        if(head == nullptr)
        {
            head = new Node(data);
            head->prev = head;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            temp->prev = head->prev;
            head->prev = temp;
            head = temp;
        }
    }
    
    void insertAtRear(int data)
    {
        if(head == nullptr)
        {
            head = new Node(data);
            head->prev = head;
        }
        else
        {
            Node *temp = new Node(data);
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
        }
    }
    
    void deleteFront()
    {
        if(head != nullptr)
        {
            if(head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node *temp = head;
                head->next->prev = head->prev;
                head = head->next;
                delete temp;
            }
        }
        else
        {
            cout<<"Deque is already empty!" <<endl;
        }
    }
    
    void deleteRear()
    {
        if(head != nullptr)
        {
            if(head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node *temp = head->prev;
                head->prev->prev->next = nullptr;
                head->prev = head->prev->prev;
                delete temp;
            }
        }
        else
        {
            cout<<"Deque is already empty!" <<endl;
        }
    }
    
    int getFront()
    {
        if(head != nullptr)
        {
            return head->data;
        }
        else
        {
            return -1;
        }
    }
    
    int getRear()
    {
        if(head != nullptr)
        {
            return head->prev->data;
        }
        else
        {
            return -1;
        }
    }
    
    void showDeque()
    {
        cout<<"Deque: ";
        if(head != nullptr)
        {
            Node *temp = head;
            while(temp != nullptr)
            {
                cout<<temp->data <<"  ";
                temp = temp->next;
            }
        }
        cout<<endl <<"----------------------------------------" <<endl;
    }
    
    void deleteDeque()
    {
        if(head != nullptr)
        {
            Node *temp = head;
            while(temp != nullptr)
            {
                Node *delNode = temp;
                temp = temp->next;
                delete delNode;
            }
            head = nullptr;
        }
    }
    
    ~Deque()
    {
        deleteDeque();
    }

};

int main()
{
    Deque d;
    d.insertAtFront(40);
    d.insertAtFront(30);
    d.insertAtRear(50);
    d.insertAtRear(60);
    d.insertAtFront(20);
    d.insertAtRear(70);
    d.insertAtFront(10);
    d.insertAtRear(80);
    d.showDeque();
    
    if(d.isEmpty())
    {
        cout<<"Deque is Empty!" <<endl;
    }
    else
    {
        cout<<"Deque is not Empty!" <<endl;
    }
    cout<<"----------------------------------------" <<endl;
    
    d.deleteFront();
    d.deleteRear();
    d.deleteFront();
    d.deleteFront();
    d.deleteRear();
    cout<<"Front: " <<d.getFront() <<endl;
    cout<<"Rear: " <<d.getRear() <<endl;
    d.showDeque();
    
    d.deleteDeque();
    
    if(d.isEmpty())
    {
        cout<<"Deque is Empty!" <<endl;
    }
    else
    {
        cout<<"Deque is not Empty!" <<endl;
    }
    cout<<"----------------------------------------" <<endl;
    
    d.showDeque();
    
    return 0;
}