#include<iostream>
using namespace std;

int partition(int A[],int l, int h)
{
    int pivot = A[l]; // pivot value
    int i = l, j = h;
    while(i<j)
    {
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i<j)
        {
            int swap = A[i];
            A[i] = A[j];
            A[j] = swap;
        }
    }
    int swap = A[l]; // pivot value
    A[l] = A[j];
    A[j] = swap;
    return j; // pivot index or position
}

void quickSort(int A[], int l, int h)
{
    if(l<h)
    {
        int pivot = partition(A,l,h); // place pivot to it's position and return it's index
        quickSort(A,l,pivot); // always sort left list of pivot
        quickSort(A,pivot+1,h); // always sort right list of pivot
    }
}

int main()
{
    const int size = 10;
    int A[size+1] = {11,13,7,12,16,9,24,5,10,3};
    A[size+1] = INT32_MAX;  // INT32_MAX is a macro having maximum positive value of int data type as infinity and including in sorting but not displayed in output

    quickSort(A,0,size);
    cout<<"Sorted Array: ";
    for(int i=0; i<size; i++)
    {
        cout<<A[i] <<"  ";
    }

    return 0;
}