#include<iostream>
using namespace std;

void linearSearch(int array[], int size, int data)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == data)
        {
            cout<<"Data is found on Index " <<i <<endl;
            return;        
        }
    }
    cout<<"Data is not found!" <<endl;
}

int main()
{
    const int size = 5;
    int array[size] = {2,4,6,8,9}, data;
    cout<<"Enter a number for Searching: ";
    cin>>data;

    linearSearch(array,size,data);
    return 0;
}