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

class SLL
{
    Node *head = nullptr;
    public:
    SLL()
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

    void insertAtStart(int data)
    {
        if(head == nullptr)
        {
            head = new Node(data);
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
        }
    }

    void insertAtLast(int data)
    {
        if(head == nullptr)
        {
            head = new Node(data);
        }
        else
        {
            Node *temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node(data);
        }
    }

    // helper function
    Node* searchNode(int key)
    {
        Node *temp = head;
        while(temp != nullptr)
        {
            if(temp->data == key)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void insertAfter(int key, int data)
    {
        Node *searchedNode = searchNode(key);
        if(searchedNode != nullptr)
        {
            if(searchedNode->next == nullptr)
            {
                searchedNode->next = new Node(data);
            }
            else
            {
                Node *temp = new Node(data);
                temp->next = searchedNode->next;
                searchedNode->next = temp;
            }
        }
        else
        {
            cout<<"Node not found!" <<endl;
        }
    }

    void show()
    {
        cout<<"Linked List: ";
        if(head != nullptr)
        {
            Node *temp = head;
            while(temp != nullptr)
            {
                cout<<temp->data <<"  ";
                temp = temp->next;
            }
        }
        cout<<endl <<"---------------------------------------" <<endl;
    }

    void deleteFirst()
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
                head = head->next;
                delete temp;
            }
        }
        else
        {
            cout<<"Linked List is already empty!" <<endl;
        }
    }

    void deleteLast()
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
                while(temp->next->next != nullptr)
                {
                    temp = temp->next;
                }
                Node *delNode = temp->next;
                temp->next = nullptr;
                delete delNode;
            }
        }
        else
        {
            cout<<"Linked List is already empty!" <<endl;
        }
    }

    void deletenode(int key)
    {
        Node *delNode = searchNode(key);
        if(delNode != nullptr)
        {
            // only one node
            if(head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            // first node but having more than one node
            else if(delNode == head && head->next != nullptr)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            // middle and last node
            else
            {
                Node *temp = head;
                while(temp->next != delNode)
                {
                    temp = temp->next;
                }
                temp->next = delNode->next;
                delete delNode;
            }
        }
        else
        {
            cout<<"Node doesn't Exist!" <<endl;
        }
    }

    void deleteSLL()
    {
        if(head != nullptr)
        {
            Node *temp = head;
            while(head != nullptr)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    }

    ~SLL()
    {
        deleteSLL();
    }
};

int main()
{
    SLL list;
    list.insertAtStart(20);
    list.insertAtLast(30);
    list.insertAtLast(50);
    list.insertAtStart(10);
    list.insertAfter(50,60);
    list.insertAfter(30,40);
    list.show();

    list.deleteFirst();
    list.deleteLast();
    list.show();

    list.deletenode(30);
    list.show();

    list.deletenode(40);
    list.show();

    list.deletenode(20);
    list.show();

    list.deletenode(50);
    list.show();

    return 0;
}