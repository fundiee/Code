#include<iostream>
using namespace std;

class Node
{
    public:
    int item;
    Node *next = NULL;
    Node(int item)
    {
        this->item = item;
    }
};

class Stack
{
    Node *top = NULL;
    int size = 0;
    public:
    Stack(int item)
    {
        top = new Node(item);
        size++;
    }

    bool isEmpty()
    {
        if(top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int item)
    {
        if(top == NULL)
        {
            top = new Node(item);
            size++;
        }
        else
        {
            Node *temp = new Node(item);
            temp->next = top;
            top = temp;
            size++;
        }
    }

    int stackSize()
    {
        return size;
    }

    void peak()
    {
        if(top != NULL)
        {
            cout<<"Top Item: " <<top->item <<endl;
        }
        else
        {
            cout<<"Stack is Empty!" <<endl;
        }
    }

    void pop()
    {
        if(top != NULL)
        {
            Node *temp = top;
            top = top->next;
            cout<<"Poped Item: " <<temp->item <<endl;
            delete temp;
            size--;
        }
        else
        {
            cout<<"Stack is Underflow!" <<endl;
        }
    }

    void clear()
    {
        if(top != NULL)
        {
            Node *temp = top;
            while(temp != NULL)
            {
                top = top->next;
                delete temp;
                temp = top;
                size--;
            }
            top = NULL;
            cout<<"Stack is Cleared!" <<endl;
            cout<<"---------------------------" <<endl;
        }
    }

    ~Stack()
    {
        clear();
    }
};

int main()
{
    Stack s(10);
    if(s.isEmpty())
    {
        cout<<"Stack is Empty!" <<endl;
    }
    else
    {
        cout<<"Stack is not Empty!" <<endl;
    }
    cout<<"---------------------------" <<endl;

    s.push(20);
    s.peak();
    cout<<"---------------------------" <<endl;

    s.push(30);
    s.push(40);
    cout<<"Stack Size: " <<s.stackSize() <<endl;
    cout<<"---------------------------" <<endl;

    s.pop();
    s.pop();
    s.pop();
    cout<<"---------------------------" <<endl;

    s.peak();
    cout<<"---------------------------" <<endl;

    return 0;
}