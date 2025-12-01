#include<iostream>
using namespace std;

// It's Adaptive Bubble Sort or Modified Bubble Sort
void bubbleSort(int array[], int size)
{
    int flag;
    for(int round = 1; round < size; round++)
    {
        flag = 0; // flag for explicit adaptive
        for(int index = 0; index < size-round; index++)
        {
            if(array[index] > array[index+1])
            {
                int swap = array[index];
                array[index] = array[index+1];
                array[index+1] = swap;
                flag = 1;
            }
        }
        if(flag == 0) // if no swapping then break no need of further sorting
        {
            return;
        }
    }
}

int main()
{
    const int size = 4;
    int array[size] = {10,5,15,20};
    bubbleSort(array,size); // array always pass by reference

    cout<<"Array after Sorting: ";
    for(int i = 0; i<size; i++)
    {
        cout<<array[i] <<"  ";
    }

    return 0;
}