#include<iostream>
using namespace std;

void selectionSort(int array[], int size)
{
    int minValIndex, searchMinValIndex;
    for(int position = 0; position < size-1; position++)
    {
        minValIndex = searchMinValIndex = position;
        while(searchMinValIndex < size)
        {
            if(array[minValIndex] > array[searchMinValIndex])
            {
                minValIndex = searchMinValIndex;
            }
            searchMinValIndex++;
        }
        int swap = array[position];
        array[position] = array[minValIndex];
        array[minValIndex] = swap;
    }

}

int main()
{
    int array[4] = {8,7,10,5};
    selectionSort(array,4);

    cout<<"Sorted Array: ";
    for(int i = 0; i < 4; i++)
    {
        cout<<array[i] <<"  ";
    }

    return 0;
}