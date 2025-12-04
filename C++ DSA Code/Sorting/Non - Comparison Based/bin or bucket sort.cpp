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

class Bin
{
    public:
    Node **bin = nullptr;
    int capacity;
    Bin(int capacity)
    {
        this->capacity = capacity;
        bin = new Node*[capacity];
        for(int i = 0; i < capacity; i++)
        {
            bin[i] = nullptr;
        }
    }

    void insertAtLast(int data, int index)
    {
        if(bin[index] == nullptr)
        {
            bin[index] = new Node(data);
        }
        else
        {
            Node *temp = bin[index];
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node(data);
        }
    }

    int deleteFirst(int index)
    {
        if(bin[index] != nullptr)
        {
            int data = bin[index]->data;
            Node *temp = bin[index];
            bin[index] = bin[index]->next;
            delete temp;
            return data;
        }
        else
        {
            return -1;
        }
    }

    ~Bin()
    {
        if(bin != nullptr)
        {
            delete []bin;
            bin = nullptr;
        }
    }
};

void binSort(int array[], int size)
{
    // find max element
    int max = array[0];
    for(int i = 0; i < size; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }

    // array of node pointers size max + 1 named Bin is created and initialized with nullptr's
    Bin b(max+1);

    // Store occurances of elements from array to bin array
    for(int i = 0; i < size; i++)
    {
        // data, index
        b.insertAtLast(array[i],array[i]);
    }

    // Moving bin values to array for sorted array
    int i = 0, j = 0;
    while(j < max + 1)
    {
        while(b.bin[j] != nullptr)
        {
            array[i++] = b.bin[j]->data;
            b.deleteFirst(j);
        }
        j++;
    }
}

int main()
{
    const int size = 8;
    int array[size] = {2,5,3,7,15,2,4,5};

    binSort(array, size);

    cout<<"Sorted Array: ";
    for(int i = 0; i < size; i++)
    {
        cout<<array[i] <<"  ";
    }
    cout<<endl;

    return 0;
}