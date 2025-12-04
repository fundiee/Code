#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Stack
{
    Node *top = nullptr;
    public:
    Stack()
    { }

    bool isEmpty()
    {
        if(top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int data)
    {
        if(top == nullptr)
        {
            top = new Node(data);
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = top;
            top = temp;
        }
    }

    int pop()
    {
        if(top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            int data = temp->data;
            delete temp;
            return data;
        }
        else
        {
            return -1;
        }
    }
};

class Edge
{
    public:
    int parent, weight, u;
};

class Heap
{
    public:
    Edge heap[100];
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
    
    void enQueueEdge(int parent, int weight, int u)
    {
        size++;
        heap[size].weight = weight;
        heap[size].parent = parent;
        heap[size].u = u;

        int i = size;

        // Child weight < Parent weight && Child Index >= 0
        while(heap[i].weight < heap[(i - 1)/2].weight && size >= 0)
        {
            // swap values = Child Values
            int swapWeight = heap[i].weight;
            int swapParent = heap[i].parent;
            int swapNode = heap[i].u;
            
            // Child values = Parent Values
            heap[i].weight = heap[(i-1)/2].weight;
            heap[i].parent = heap[(i-1)/2].parent;
            heap[i].u = heap[(i-1)/2].u;
            
            // Parent values = Child Values from Swap
            heap[(i-1)/2].weight = swapWeight;
            heap[(i-1)/2].parent = swapParent;
            heap[(i-1)/2].u = swapNode;
            
            // Child Index = Parent Index
            i = (i-1)/2;
        }
    }
    
    Edge deQueueEdge()
    {
        int i = 0;
        
        Edge deletedElement;
        deletedElement.weight = heap[i].weight;
        deletedElement.parent = heap[i].parent;
        deletedElement.u = heap[i].u;
        
        heap[i].weight = heap[size].weight;
        heap[i].parent = heap[size].parent;
        heap[i].u = heap[size].u;

        // Left Child Index = 2 * ParentIndex + 1
        int leftChildIndex = 2 * i + 1;
        // Right Child Index = 2 * Parent Index + 2
        int rightChildIndex = 2 * i + 2;
        int smallerChildIndex;

        while(leftChildIndex < size)
        {
            // Only left Child Exist
            if(leftChildIndex < size && rightChildIndex == size)
            {
                smallerChildIndex = leftChildIndex;
            }
            // Both Left and Right Child Exists
            else
            {
                if(heap[leftChildIndex].weight < heap[rightChildIndex].weight)
                {
                    smallerChildIndex = leftChildIndex;
                }
                else
                {
                    smallerChildIndex = rightChildIndex;
                }
            }
            // Smaller Child weight < Parent weight
            if(heap[smallerChildIndex].weight < heap[i].weight)
            {
                int swapWeight = heap[smallerChildIndex].weight;
                int swapParent = heap[smallerChildIndex].parent;
                int swapNode = heap[smallerChildIndex].u;
                
                heap[smallerChildIndex].weight = heap[i].weight;
                heap[smallerChildIndex].parent = heap[i].parent;
                heap[smallerChildIndex].u = heap[i].u;
                
                heap[i].weight = swapWeight;
                heap[i].parent = swapParent;
                heap[i].u = swapNode;

                i = smallerChildIndex;
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

class DiGraph
{
    int **adjMatrix = nullptr;
    int vertexCount;
    public:
    DiGraph(int vertexCount)
    {
        this->vertexCount = vertexCount;
        adjMatrix = new int*[vertexCount];

        for(int row = 0; row < vertexCount; row++)
        {
            adjMatrix[row] = new int[vertexCount];

            for(int i = 0; i < vertexCount; i++)
            {
                adjMatrix[row][i] = 0;
            }
        }
    }

    void addEdge(int u, int v, int weight = 1)
    {
        if(u > -1 && u < vertexCount && v > -1 && v < vertexCount)
        {
            adjMatrix[u][v] = weight;
        }
        else
        {
            cout<<"Invalid Vertices!" <<endl;
        }
    }

    void dijkstraAlgorithm(int sink)
    {
        int *totalDistTo = new int[vertexCount];
        Edge *edgeTo = new Edge[vertexCount];
        for(int i = 0; i < vertexCount; i++)
        {
            totalDistTo[i] = INT32_MAX;
            edgeTo[i].parent = i;
            edgeTo[i].weight = 0;
            edgeTo[i].u = i;
        }

        int source = 0;
        totalDistTo[source] = 0;

        edgeTo[source].parent = source;
        edgeTo[source].weight = 0;
        edgeTo[source].u = source; 
        
        Heap pq;
        pq.enQueueEdge(source,0,source);

        while(!pq.isEmpty())
        {
            Edge e = pq.deQueueEdge();
            for(int v = 0; v < vertexCount; v++)
            {
                if(adjMatrix[e.u][v] != 0)
                {
                    if(totalDistTo[e.parent] + adjMatrix[e.u][v] < totalDistTo[v])
                    {
                        totalDistTo[v] = totalDistTo[e.u] + adjMatrix[e.u][v];

                        edgeTo[v].parent = e.u;
                        edgeTo[v].weight = totalDistTo[e.u] + adjMatrix[e.u][v];
                        edgeTo[v].u = v;
                        
                        pq.enQueueEdge(e.parent,(totalDistTo[e.parent] + adjMatrix[e.u][v]),v);
                    }
                }
            }
        }

        // Printing Logic
        Stack s;
        cout<<"--Single Source Shortest Path Implementation--" <<endl;
        if(sink == edgeTo[sink].parent && source != sink)
        {
            cout<<"Source (" <<source <<") to sink(" <<sink <<") is not possible because vertex is unreachable!" <<endl;
            return;
        }
        else
        {
            for(int i = sink; i > 0; i = edgeTo[i].parent)
            {
                s.push(i);
            }
            s.push(0);
        }

        cout<<"Source(0) to Sink(" <<sink <<"): ";
        while(!s.isEmpty())
        {
            cout<<s.pop() <<"   ";
        }
        cout<<endl <<"Total distance: " <<totalDistTo[sink] <<endl;
        cout<<"----------------------------------------------" <<endl;

        // Free memory resources
        delete[] totalDistTo,edgeTo;
        totalDistTo = nullptr, edgeTo = nullptr;
    }
};

int main()
{
    DiGraph g(5);
    // u, v, weight
    g.addEdge(0,1,2);
    g.addEdge(0,3,9);
    g.addEdge(0,4,25);
    g.addEdge(1,2,4);
    g.addEdge(1,3,1);
    g.addEdge(3,2,6);
    g.addEdge(3,4,7);

    g.dijkstraAlgorithm(4);

    return 0;
}