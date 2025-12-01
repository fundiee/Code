#include<iostream>
using namespace std;

class ProfitByWeightAndIndex
{
    public:
    float profitByWeight;
    int index;
};

class Heap
{
    public:
    ProfitByWeightAndIndex heap[100];
    int size = -1;
    Heap()
    { }

    bool isEmpty()
    {
        if(size == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(float profitByWeight, int index)
    {
        size++;
        heap[size].profitByWeight = profitByWeight;
        heap[size].index = index;


        int i = size;

        // Child Value > Parent Value && Child Index >= 0
        while(heap[i].profitByWeight > heap[(i - 1)/2].profitByWeight && size >= 0)
        {
            // swap = Child Value
            float swapProfitByWeight = heap[i].profitByWeight;
            int swapIndex = heap[i].index; 

            // Child = Parent Value
            heap[i].profitByWeight = heap[(i-1)/2].profitByWeight;
            heap[i].index = heap[(i-1)/2].index;

            // Parent = Child Value from Swap
            heap[(i-1)/2].profitByWeight = swapProfitByWeight;
            heap[(i-1)/2].index = swapIndex;

            // Child Index = Parent Index
            i = (i-1)/2;
        }
    }

    ProfitByWeightAndIndex deleteElement()
    {
        int i = 0;
        ProfitByWeightAndIndex deletedElement;
        deletedElement.profitByWeight = heap[i].profitByWeight;
        deletedElement.index = heap[i].index;

        heap[i].profitByWeight = heap[size].profitByWeight;
        heap[i].index = heap[size].index;


        // Left Child Index = 2 * ParentIndex + 1
        int leftChildIndex = 2 * i + 1;
        // Right Child Index = 2 * Parent Index + 2
        int rightChildIndex = 2 * i + 2;
        int greaterChildIndex;

        while(leftChildIndex < size)
        {
            // Only left Child Exist
            if(leftChildIndex < size && rightChildIndex == size )
            {
                greaterChildIndex = leftChildIndex;
            }
            // Both Left and Right Child Exists
            else
            {
                if(heap[leftChildIndex].profitByWeight > heap[rightChildIndex].profitByWeight)
                {
                    greaterChildIndex = leftChildIndex;
                }
                else
                {
                    greaterChildIndex = rightChildIndex;
                }
            }
            // Greater Child Value  > Parent Value
            if(heap[greaterChildIndex].profitByWeight > heap[i].profitByWeight)
            {
                float swapProfitByWeight = heap[greaterChildIndex].profitByWeight;
                int swapIndex = heap[greaterChildIndex].index;

                heap[greaterChildIndex].profitByWeight = heap[i].profitByWeight;
                heap[greaterChildIndex].index = heap[i].index;

                heap[i].profitByWeight = swapProfitByWeight;
                heap[i].index = swapIndex;

                i = greaterChildIndex;
                leftChildIndex = 2 * i + 1;
                rightChildIndex = 2 * i + 2;
            }
            else
            {
                break;
            }
        }
        size--;

        return deletedElement;
    }
};

void knapsack(int objects[], float profits[], float weights[], int noOfObjects, float knapsackCapacity)
{
    const int size = noOfObjects;
    float profitByWeight[size];
    for(int i = 0; i < noOfObjects; i++)
    {
        profitByWeight[i] = profits[i]/weights[i];
    }

    Heap h;
    for(int index = 0; index < noOfObjects; index++)
    {
        h.insert(profitByWeight[index], index);
    }

    float includedQuantity[size];
    float remainingWeight = knapsackCapacity;
    while(!h.isEmpty())
    {
        ProfitByWeightAndIndex element = h.deleteElement();
        if(remainingWeight >= weights[element.index])
        {
            // includedQuantity[element.index] = 1;
            includedQuantity[element.index] = weights[element.index] / weights[element.index];
            remainingWeight = remainingWeight - weights[element.index];
        }
        else if(remainingWeight != 0)
        {
            // includeQuantity[element.index] = 2 / 3; 
            includedQuantity[element.index] = remainingWeight / weights[element.index];
            remainingWeight = remainingWeight - remainingWeight;
        }
        else
        {
            // includeQuantity[element.index] = 0 / 7;
            includedQuantity[element.index] = remainingWeight / weights[element.index];
        }
    }

    float totalWeightOfIncludedObjects = 0;
    float totalProfitOfIncludedObjects = 0;

    for(int i = 0; i < noOfObjects; i++)
    {
        totalWeightOfIncludedObjects = totalWeightOfIncludedObjects + (includedQuantity[i] * weights[i]);
        totalProfitOfIncludedObjects = totalProfitOfIncludedObjects + (includedQuantity[i] * profits[i]); 
    }

    cout<<"Knapsack total capacity: " <<knapsackCapacity <<endl;
    for(int i = 0; i < noOfObjects; i++)
    {
        cout<<"Object " <<i+1 <<" occurance " <<includedQuantity[i] <<" and weight " <<includedQuantity[i] * weights[i] <<endl;
    }
    cout<<"Total weight of included objects: " <<totalWeightOfIncludedObjects <<endl;
    cout<<"Total profit of included objects: " <<totalProfitOfIncludedObjects <<endl;
    cout<<"------------------------------------------" <<endl;
}

int main()
{
    int noOfObjects = 7;
    float knapsackCapacity = 15;

    int objects[7]  = {1,  2,  3,  4,  5,  6,  7};
    float profits[7] = {10, 5,  15, 7,  6,  18, 3};
    float weights[7] = {2,  3,  5,  7,  1,  4,  1}; 

    knapsack(objects, profits, weights, noOfObjects, knapsackCapacity);
    
    return 0;
}