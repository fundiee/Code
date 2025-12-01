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

class CSLL
{
    Node *tail = nullptr;
    public:
    CSLL()
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

    void insertAtStart(int data)
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
        }
    }

    void insertAtLast(int data)
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

    void insertAfter(int key, int data)
    {
        if(tail != nullptr)
        {
            Node *temp = tail->next;
            while(temp != tail)
            {
                if(temp->data == key)
                {
                    Node *newNode = new Node(data);
                    newNode->next = temp->next;
                    temp->next = newNode;
                    return;
                }
                temp = temp->next;
            }
            if(temp->data == key)
            {
                Node *newNode = new Node(data);
                newNode->next = temp->next;
                temp->next = newNode;
                tail = newNode;
            }
        }

    }

    void show()
    {
        cout<<"List: ";
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
        cout<<endl;
    }

    void deleteFirst()
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
    }  

    void deleteLast()
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
                Node *delNode = tail;
                Node *temp = tail->next;
                while(temp->next != tail)
                {
                    temp = temp->next;
                }
                temp->next = tail->next;
                delete tail;
                tail = temp;
            }
        }
    }

    // Helper function
    Node* searchNode(int data)
    {
        if(tail != nullptr)
        {
            Node *temp = tail->next;
            while(temp != tail)
            {
                if(temp->data == data)
                {
                    return temp;
                }
                temp = temp->next;
            }
            if(temp->data == data)
            {
                return temp;
            }
        }
        return nullptr;
    }

    void deleteNode(int data)
    {
        Node *delNode = searchNode(data);
        if(delNode != nullptr)
        {
            // Only one node
            if(tail->next == tail)
            {
                delete tail;
                tail = nullptr;
                return;
            }
            else
            {
                // Last Node
                Node *temp = tail->next;
                if(delNode == tail)
                {
                    while(temp->next != tail)
                    {
                        temp = temp->next;
                    }
                    temp->next = temp->next->next;
                    delete delNode;
                    tail = temp;
                    return;
                }

                // Any Middle and First Node
                while(temp->next != delNode)
                {
                    temp = temp->next;
                }
                temp->next = delNode->next;
                delete delNode;
            }
        }
    }

    void clearList()
    {
        if(tail != nullptr)
        {
            Node *temp = tail->next;
            while(temp != tail)
            {
                tail->next = temp->next;
                delete temp;
                temp = tail->next;
            }
            delete tail;
            tail = nullptr;
        }
    }

    ~CSLL()
    {
        clearList();
    }
        
};

int main()
{

    CSLL list;
    list.insertAtStart(30);
    list.insertAtLast(40);
    list.insertAtStart(20);
    list.insertAtLast(50);
    list.insertAtStart(10);
    list.insertAtLast(60);

    list.show();

    list.insertAfter(10,15);
    list.show();

    list.insertAfter(30,35);
    list.insertAfter(60,65);
    list.show();

    list.deleteFirst();
    list.deleteLast();
    list.deleteFirst();
    list.deleteLast();
    list.show();

    list.deleteNode(20);
    list.deleteNode(50);
    list.deleteNode(35);
    list.show();

    return 0;
}