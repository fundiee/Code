#include<iostream>
using namespace std;

class Stack
{
    int capacity = -1, top1 = -1, top2 = -1, *array = NULL;
    public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        top2 = capacity;
        array = new int[capacity];
    }

    void push1(int data)
    {
        if(top2 - top1 > 1)
        {
            top1++;
            array[top1] = data;
        }
        else
        {
            cout<<"-----Stack is Overflow!-----" <<endl;
        }
    }

    void push2(int data)
    {
        if(top2 - top1 > 1)
        {
            top2--;
            array[top2] = data;
        }
        else
        {
            cout<<"-----Stack is Overflow!-----" <<endl;
        }
    }

    void pop1()
    {
        if(top1 > -1)
        {
            top1--;
        }
        else
        {
            cout<<"-----Stack is Underflow!-----" <<endl;
        }
    }

    void pop2()
    {
        if(top2 < capacity)
        {
            top2++;
        }
        else
        {
            cout<<"-----Stack is Underflow!-----" <<endl;
        }
    }

    ~Stack()
    {
        // Not Implemented to free memory resources
    }
};

int main()
{
    Stack s(5);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push2(50);

    s.push2(60); // Stack is Overflow!

    s.pop1();
    s.pop1();
    s.pop1();
    s.pop1();
    s.pop1(); // Stack is Underflow!

    s.pop2();
    s.pop2(); // Stack is Underflow!

    return 0;
}