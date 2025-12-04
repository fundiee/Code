#include<iostream>
#include<string>
using namespace std;

class Stack
{
    string str = "";
    int count = -1;
    public:
    bool isEmpty()
    {
        if(str.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(char ch)
    {
        count++;
        str = str + ch;
    }

    char pop()
    {
        if(count != -1)
        {
            count--;
            return str[count+1];
        }
        else
        {
            return '|'; // sentinel
        }
    }
};

int main()
{
    Stack s;
    string str = "Hello";

    for(int i = 0; i<str.length(); i++)
    {
        int ch = str[i];
        s.push(ch);
    }

    string reversedString;
    while(!s.isEmpty())
    {
        char ch = s.pop();
        if(ch == '|')
        {
            break;
        }
        reversedString = reversedString + ch;
    }

    cout<<reversedString << endl; // olleH

    return 0;
}