#include <iostream>
#include <vector>
using namespace std;

void printSubsequence(int array[], int arraySize, int index, vector<int> &list )
{
    if(index == arraySize)
    {
        if(list.empty())
        {
            cout<<"{}" <<endl;
            return;
        }

        for(int i = 0; i < list.size(); i++)
        {
            cout<<list[i] <<"  ";
        }
        cout<<endl;
        return;
    }
    
    list.push_back(array[index]);
    printSubsequence(array, arraySize, index + 1, list);
    list.pop_back();
    // if we want subsequence from {} to 312 then place this line before list.push_back() line
    printSubsequence(array, arraySize, index + 1, list);
}

int main()
{
    int array[3] = {3,1,2};
    vector<int> list;
    printSubsequence(array, 3,0,list);
    
    return 0;
}