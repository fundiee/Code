#include<iostream>
using namespace std;

void countSort(int array[], int arraySize)
{
    // Find max element
    int max = array[0];
    for(int i = 0; i < arraySize; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }

    // Create count array max + 1 size and initialize it with zero's
    int *count = new int[max+1];
    for(int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Store occurances of elements from array to count array
    for(int i = 0; i < arraySize; i++)
    {
        count[array[i]]++;
    }

    /* 
       Move j pointer of count array from zero to max + 1 and if found any 
       occurance then store j's value in array and increament i pointer of 
       array and don't increament j if found occurance 
    */
   int i = 0, j = 0;
   while(j < max + 1)
   {
    if(count[j] > 0)
    {
        // post decreament
        array[i++] = j;
        count[j]--;
    }
    else
    {
        j++;
    }
   }

   // heap memory management
   delete []count;
}

int main()
{
    const int size = 8;
    int array[size] = {2,5,3,7,15,2,4,5};

    countSort(array, size);

    cout<<"Sorted Array: ";
    for(int i = 0; i < size; i++)
    {
        cout<<array[i] <<"  ";
    }
    cout<<endl;
    
    return 0;
}