// shuffle the array
// In QuickSort: if l < h then perform 3 tasks:
// partitioning: first place the pivot to its place and then get index of left sublist high, that divide the array to two sublists
// call for left sublist
// call for right sublist

#include<iostream>
#include<cstdint>   // for INT32_MAX
#include<cstdlib>   // for rand, srand
#include<ctime>     // for time
using namespace std;

// Fisher-Yates (Knuth) Shuffle
void shuffleArray(int A[], int n)
{
    for(int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

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
    A[l] = A[j];
    A[j] = pivot;
    return j; // pivot's swapped position index and leftHigh
}

void quickSort(int A[], int l, int h)
{
    if(l<h)
    {
        
        int pivotIndex = partition(A,l,h); // place pivot to it's position and return it's updated index
        // here pivotIndex is helped as leftHigh
        quickSort(A,l,pivotIndex); // sort left list of pivot
        quickSort(A,pivotIndex+1,h); // sort right list of pivot
    }
}

int main()
{
    const int size = 10;
    int A[size+1] = {11,13,7,12,16,9,24,5,10,3};

    srand(time(0));          // seed random number generator
    shuffleArray(A, size);  
    
    A[size] = INT32_MAX;     // sentinel stays at the end
    quickSort(A,0,size);

    cout<<"Sorted Array: ";
    for(int i=0; i<size; i++)
    {
        cout<<A[i] <<"  ";
    }

    return 0;
}
