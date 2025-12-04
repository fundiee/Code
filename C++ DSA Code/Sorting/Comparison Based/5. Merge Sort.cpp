#include<iostream>
using namespace std;

void merge(int A[], int l, int mid, int h)
{
    // i for first list, j for 2nd list and k for Auxiliary array
    int i = l, j = mid+1, k = l;
    int auxiliary[h+1];
    
    /* Merging two lists but one list will full copy to auxiliary 
       and other list have one or more elements left
    */
    while(i <= mid && j <= h)
    {
        if(A[i] <= A[j]) // = operator made it stable algorithm
        {
            auxiliary[k++] = A[i++]; // postfix increament 
        }
        else
        {
            auxiliary[k++] = A[j++]; // postfix increament
        }
    }
    
    /* only one while loop will execute because one list is finished 
       and one list left
    */
    while(i <= mid)
    {
        auxiliary[k++] = A[i++]; // postfix increament
    }
    while(j <= h)
    {
        auxiliary[k++] = A[j++]; // postfix increament
        
        
    }
    
     // copy data data from auxiliary to original array
    for(i = l; i <= h; i++)
    {
        A[i] = auxiliary[i];
    }
}

void mergeSort(int A[], int l, int h)
{
    if(l<h) // execute till minimum 2 elements and i = j means only one element in array
    {
        int mid = (l+h)/2; // updating mid value
        mergeSort(A,l,mid); // call that divide always left sub array of current array
        mergeSort(A,mid+1,h); // call that divide always right sub array of current array
        merge(A,l,mid,h); // call that merge left and right sub arrays
    }
}

int main()
{
    const int size = 8;
    int array[size] = {4,2,9,7,8,3,5,2};

    mergeSort(array,0,size-1);

    cout<<"Sorted Array: ";
    for(int i = 0; i < size; i++)
    {
        cout<<array[i] <<"  ";
    }

    return 0;
}