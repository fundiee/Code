#include<iostream>
using namespace std;

int binarySearch(int array[], int size,int l, int h, int key)
{
    int mid = (l+h)/2;
    if(l<=h)
    {
        if(array[mid] == key) // data is always found on mid
        {
            return mid; // index
        }
        else if(array[mid] > key)
        {
            return binarySearch(array,size,l,mid-1,key); // return keyword is imp
        }
        else
        {
            return binarySearch(array,size,mid+1,h,key); // return keyword is imp
        }
    }
    
    return -1; // -1 index if data not found!
}

int main()
{
    const int size = 9;
    int array[size] = {10,20,30,40,50,60,70,80,90}, num;
    cout<<"Enter a number to Search: ";
    cin>>num;

    int searchedNumIndex = binarySearch(array, size,0,size-1, num);
    
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