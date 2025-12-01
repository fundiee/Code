#include<iostream>
using namespace std;

class Heap
{
    public:
    Heap()
    { }
    void insert(int array[], int index)
    {
        // Child Value > Parent Value && Child Index >= 0
        while(array[index] > array[(index - 1)/2] && index >= 0)
        {
            // swap = Child Value
            int swap = array[index];
            // Child = Parent Value
            array[index] = array[(index-1)/2];
            // Parent = Child Value from Swap
            array[(index-1)/2] = swap;
            // Child Index = Parent Index
            index = (index-1)/2;
        }
    }
    void createHeap(int array[], int size)
    {
        for(int index = 1; index < size; index++)
        {
            insert(array,index);
        }
    }
    void show(int array[], int size)
    {
        for(int i = 0; i < size; i++)
        {
            cout<<array[i] <<"  ";
        }
        cout<<endl <<"---------------------------------------------------" <<endl;
    }
    int deleteElement(int heap[], int heapSize)
    {
        int index = 0;
        int deletedElement = heap[index];
        heap[index] = heap[heapSize-1];

        // Left Child Index = 2 * ParentIndex + 1
        int leftChildIndex = 2 * index + 1;
        // Right Child Index = 2 * Parent Index + 2
        int rightChildIndex = 2 * index + 2;
        int greaterChildIndex;

        while(leftChildIndex < heapSize)
        {
            // Only left Child Exist
            if(leftChildIndex < heapSize && rightChildIndex == heapSize )
            {
                greaterChildIndex = leftChildIndex;
            }
            // Both Left and Right Child Exists
            else
            {
                if(heap[leftChildIndex] > heap[rightChildIndex])
                {
                    greaterChildIndex = leftChildIndex;
                }
                else
                {
                    greaterChildIndex = rightChildIndex;
                }
            }
            // Greater Child Value  > Parent Value
            if(heap[greaterChildIndex] > heap[index])
            {
                int swap = heap[greaterChildIndex];
                heap[greaterChildIndex] = heap[index];
                heap[index] = swap;

                index = greaterChildIndex;
                leftChildIndex = 2 * index + 1;
                rightChildIndex = 2 * index + 2;
            }
            else
            {
                break;
            }
        }
        return deletedElement;
    }

    void deleteHeap(int array[], int size)
    {
        int heapSize = size;
        for(int i = 1; i < size; i++)
        {
            array[heapSize-1] = deleteElement(array, heapSize);
            heapSize--;
        }
    }
    void HeapSort(int array[], int size)
    {
        createHeap(array,size);
        deleteHeap(array,size);
    }
};

int main()
{
    // Create Array #1
    int array1[6] = {20,30,90,60,40,50};

    Heap h;

    cout<<"Array1 before Heap: ";
    h.show(array1, 6);

    // Created Heap
    h.createHeap(array1,6);

    // Print Heap
    cout<<"Heap: ";
    h.show(array1,6);

    // Delete Heap
    h.deleteHeap(array1,6);
    cout<<"Array1 After Heap Deletion: ";
    h.show(array1,6);

    // Create Array #2
    int array2[11] = {20,30,110,90,60,40,50,100,70,10,80};

    Heap hs;
    // Heap Sort
    hs.HeapSort(array2,11);

    // Array #2 after
    cout<<"Heap Sort: ";
    hs.show(array2,11);

    return 0;
}