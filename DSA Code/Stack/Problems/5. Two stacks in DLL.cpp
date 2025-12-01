#include<iostream>
using namespace std;

class Node
{
    public:
    int item;
    Node *prev = NULL, *next = NULL;
    Node(int item)
    {
        this->item = item;
    }
};

class Stack
{
    Node *top1 = NULL, *top2 = NULL;
    int count1 = 0, count2 = 0;
    public:
    Stack()
    { }

    void push1(int item)
    {
        if(top1 == NULL && top2 == NULL)
        {
            top1 = new Node(item);
            top2 = top1;
            count1++;
        }
        else
        {
            Node *temp = new Node(item);
            temp->next = top1;
            top1->prev = temp;
            top1 = temp;
            count1++;
        }
    }

    void push2(int item)
    {
        if(top1 == NULL && top2 == NULL)
        {
            top2 = new Node(item);
            top1 = top2;
            count2++;
        }
        else
        {
            Node *temp = new Node(item);
            temp->prev = top2;
            top2->next = temp;
            top2 = temp;
            count2++;
        }
    }

    void pop1()
    {
        if(count1 != 0)
        {
            if(top1->next == NULL)
            {
                delete top1;
                top1 = NULL;
                top2 = NULL;
                count1--;
            }
            else
            {
                Node *temp = top1;
                top1 = top1->next;
                top1->prev = NULL;
                delete temp;
                count1--;
            }
        }
        else
        {
            cout<<"Stack1 is Underflow!" <<endl;
        }
    }

    void pop2()
    {
        if(count2 != 0)
        {
            if(top2->prev == NULL)
            {
                delete top2;
                top2 = NULL;
                top1 = NULL;
                count2--;
            }
            else
            {
                Node *temp = top2;
                top2 = top2->prev;
                top2->next = NULL;
                delete temp;
                count2--;
            }
        }
        else
        {
            cout<<"Stack2 is Underflow!" <<endl;
        }
    }

    ~Stack()
    {
        // destructor not implemented to avoid memory leak because of time
    }
};

int main()
{
    Stack s;
    s.push1(10);
    s.push1(20);
    s.push2(30);

    s.pop1();
    s.pop1();
    s.pop1(); // Stack1 is Underflow!

    s.pop2();
    s.pop2(); // Stack2 is Underflow!

    return 0;
}