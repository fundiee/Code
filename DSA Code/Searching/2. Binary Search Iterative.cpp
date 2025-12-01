#include<iostream>
using namespace std;

int binarySearch(int array[], int size, int key)
{
    int l = 0, h = size-1, mid = (l+h)/2;
    while(l<=h)
    {
        if(array[mid] == key) // data is always found on mid
        {
            return mid; // index
        }
        else if(array[mid] > key)
        {
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
        mid = (l+h)/2;
    }
    return -1; // -1 index if data not found!
}

int main()
{
    const int size = 8;
    int array[8] = {10,20,30,40,50,60,70,80}, num;
    cout<<"Enter a number to search: ";
    cin>>num;

    int searchedNumIndex = binarySearch(array,size,num);
    if(searchedNumIndex != -1)
    {
        cout<<"Searched Data: " <<array[searchedNumIndex] <<endl;
    }
    else
    {
        cout<<"Data Not Found!" <<endl;
    }

    return 0;
}