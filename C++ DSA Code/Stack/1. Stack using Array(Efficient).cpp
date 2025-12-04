#include<iostream>
using namespace std;

class Stack
{
    int top = -1, capacity = 0, *array = NULL;
    public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        array = new int[capacity];
    }

    bool isEmpty()
    {
        if(top > -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void push(int data)
    {
        if(top+1 < capacity)
        {
            array[top+1] = data;
            top++;
        }
        else
        {
            cout<<"Stack is Overflow!" <<endl;
        }
    }

    int size()
    {
        if(array != NULL)
        {
            return (top+1);
        }
        else
        {
            return -1; // stack doesn't exist
        }
    }

    int _capacity()
    {
        if(array != NULL)
        {
            return capacity;
        }
        else
        {
            return -1; // stack doesn't exist
        }
    }

    void peak()
    {
        if(array != NULL)
        {
            if(top > -1)
            {
                cout<<"Top Element: " <<array[top] <<endl;
            }
            else
            {
                cout<<"Stack is Empty!" <<endl;
            }
        }
        else
        {
            cout<<"Stack Doesn't Exist!" <<endl;
        }
    }

    void pop()
    {
        if(top > -1)
        {
            cout<<"Poped Element: " <<array[top] <<endl;
            top--;
        }
        else
        {
            cout<<"Stack is Underflow!" <<endl;
        }
    }

    bool isFull()
    {
        if(top+1 == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void deleteStack()
    {
        if(array != NULL)
        {
            delete []array;
            array = NULL;
            cout<<"Stack is Deleted!" <<endl;
            cout<<"----------------------------------" <<endl;
        }
    }

    ~Stack()
    {
        deleteStack();
    }
};

int main()
{
    Stack s(5);
    s.peak();
    cout<<"----------------------------------" <<endl;

    s.push(10);
    if(s.isEmpty())
    {
        cout<<"Stack is Empty!" <<endl;
    }
    else
    {
        cout<<"Stack is not Empty!" <<endl;
    }
    s.peak();
    cout<<"----------------------------------" <<endl;

    s.push(20);
    s.push(30);
    cout<<"Total Elements in Stack: " <<s.size() <<endl;
    cout<<"Total Capacity of Stack: " <<s._capacity() <<endl;
    s.peak();
    cout<<"----------------------------------" <<endl;

    s.push(40);
    s.push(50);
    cout<<"Total Elements in Stack: " <<s.size() <<endl;
    cout<<"Total Capacity of Stack: " <<s._capacity() <<endl;
    s.peak();
    if(s.isFull())
    {
        cout<<"Stack is Full!" <<endl;
    }
    else
    {
        cout<<"Stack is not Full!" <<endl;
    }
    cout<<"----------------------------------" <<endl;

    s.push(60); // Stack is Overflow!
    cout<<"----------------------------------" <<endl;

    s.pop();
    s.pop();
    s.pop();
    s.peak();
    cout<<"----------------------------------" <<endl;

    s.deleteStack();

    return 0;
}