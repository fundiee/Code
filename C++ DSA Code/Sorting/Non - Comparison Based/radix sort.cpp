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

class Radix
{
    public:
    Node **bin = nullptr;
    int radix;
    Radix(int radix)
    {
        // Base of a number system
        this->radix = radix;
        bin = new Node*[radix];
        for(int i = 0; i < radix; i++)
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

    ~Radix()
    {
        if(bin != nullptr)
        {
            delete []bin;
            bin = nullptr;
        }
    }
};

void radixSort(int array[], int size, int radix)
{
    // Find max element
    int max = array[0];
    for(int i = 0; i < size; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }

    int div = 1;
    Radix b(radix);
    // max handles rounds for spliting and sorting digits
    while(max > 0)
    {
        // adding nodes in bin
        for(int i = 0; i < size; i++)
        {
            // data, index
            b.insertAtLast(array[i], (array[i]/div)%radix);
        }

        // adding elements from bin to array
        int i = 0;
        for(int j = 0; j < radix; j++)
        {
            while(b.bin[j] != nullptr)
            {
                array[i++] = b.deleteFirst(j);
            }
        }

        // updations for next round
        div = div * 10;
        max = max / 10;
    }
}

int main()
{
    const int size = 8;
    int array[8] = {125, 34, 233, 60, 21, 335, 450, 70};

    int radix = 10;
    radixSort(array, size, radix);

    cout<<"Sorted Array: ";
    for(int i = 0; i < size; i++)
    {
        cout<<array[i] <<"  ";
    }
    cout<<endl;

    return 0;
}