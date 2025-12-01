#include<iostream>
using namespace std;

void insertionSort(int array[], int size)
{
    for(int round = 1; round < size; round++)
    {
        int temp = array[round];
        int index = round-1; // assinging greatest most element of subarray
        while(index >= 0 && array[index] > temp) // or index > -1 & loop execute only if temp is less than compared element (shifting loop)
        {
            array[index+1] = array[index]; // shifting subarray to right one by one
            index--;
        }
        array[index+1] = temp; 
    }
}

int main()
{
    int array[4] = {8, 6, 5, 9};
    insertionSort(array, 4);
    cout<<"Sorted array: ";
    for(int i=0; i<4; i++)
    {
        cout<<array[i] <<"  ";
    }

    return 0;
}