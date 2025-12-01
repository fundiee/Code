#include<iostream>
#include<vector>
using namespace std;

void sumOfSubsets(int array[], int arraySize, int index, vector<int> &list, int sum)
{
    if(index == arraySize)
    {
        cout<<sum <<"  ";
        return;
    }

    list.push_back(array[index]);
    sum += array[index];
    sumOfSubsets(array, arraySize, index + 1, list, sum);
    list.pop_back();
    sum -= array[index];
    sumOfSubsets(array, arraySize, index + 1, list, sum);

}

int main()
{
    int array[] = {3,1,2};
    vector<int> list;
    cout<<"Sum of Subsets: ";
    sumOfSubsets(array, 3, 0, list, 0); 
    cout<<endl <<endl;

    return 0;
}