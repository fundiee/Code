#include<iostream>
using namespace std;

class Edge
{
    public:
    int parent, weight, node;
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
    
    void insertEdge(int parent, int weight, int node)
    {
        size++;
        heap[size].weight = weight;
        heap[size].parent = parent;
        heap[size].node = node;

        int i = size;

        // Child weight < Parent weight && Child Index >= 0
        while(heap[i].weight < heap[(i - 1)/2].weight && size >= 0)
        {
            // swap values = Child Values
            int swapWeight = heap[i].weight;
            int swapParent = heap[i].parent;
            int swapNode = heap[i].node;
            
            // Child values = Parent Values
            heap[i].weight = heap[(i-1)/2].weight;
            heap[i].parent = heap[(i-1)/2].parent;
            heap[i].node = heap[(i-1)/2].node;
            
            // Parent values = Child Values from Swap
            heap[(i-1)/2].weight = swapWeight;
            heap[(i-1)/2].parent = swapParent;
            heap[(i-1)/2].node = swapNode;
            
            // Child Index = Parent Index
            i = (i-1)/2;
        }
    }
    
    Edge deleteEdge()
    {
        int i = 0;
        
        Edge deletedElement;
        deletedElement.weight = heap[i].weight;
        deletedElement.parent = heap[i].parent;
        deletedElement.node = heap[i].node;
        
        heap[i].weight = heap[size].weight;
        heap[i].parent = heap[size].parent;
        heap[i].node = heap[size].node;

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
                int swapNode = heap[smallerChildIndex].node;
                
                
                heap[smallerChildIndex].weight = heap[i].weight;
                heap[smallerChildIndex].parent = heap[i].parent;
                heap[smallerChildIndex].node = heap[i].node;
                
                
                heap[i].weight = swapWeight;
                heap[i].parent = swapParent;
                heap[i].node = swapNode;

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

class DSU
{
    int *parent = nullptr, *rootSize = nullptr, capacity;
    public:
    DSU(int capacity)
    {
        this->capacity = capacity;
        parent = new int[capacity];
        rootSize = new int[capacity];
        for(int i = 0; i < capacity; i++)
        {
            parent[i] = i;
            rootSize[i] = 1;
        }
    }
    
    int findRoot(int vertex)
    {
        // Finding root
        int root = vertex;
        while(root != parent[root])
        {    
            root = parent[root];
        }
        
        // Path compression
        while(vertex != root)
        {
            int tempParent = parent[vertex];
            parent[vertex] = root;
            vertex = tempParent;
        }
        
        return root;
    }
    
    void Union(int u, int v)
    {
        int i = findRoot(u);
        int j = findRoot(v);
        
        if(i == j)
        {
            return;
        }
        
        if(rootSize[i] < rootSize[j])
        {
            parent[i] = j;
            rootSize[j] = rootSize[j] + rootSize[i];
        }
        else
        {
            parent[j] = i;
            rootSize[i] = rootSize[i] + rootSize[j];
        }    
    }
    
    bool isConnected(int u, int v)
    {
        if(findRoot(u) == findRoot(v))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Graph
{
    // vertex count should be start from 0 (according to this implementation)
    int vertexCount = -1;
    int **adjMatrix = nullptr;
    public:
    Graph(int vertexCount)
    {
        if(vertexCount > 0)
        {
            this->vertexCount = vertexCount;
            // Adjacency Matrix = square matrix of vertexCount * vertexCount
            adjMatrix = new int*[vertexCount];
            for(int rows = 0; rows < vertexCount; rows++)
            {
                adjMatrix[rows] = new int[vertexCount];
                // Initializing it with zero's
                for(int columns = 0; columns < vertexCount; columns++)
                {
                    adjMatrix[rows][columns] = 0;
                }
            }
        }
        else
        {
            cout<<"Invalid Size, Graph is not created!" <<endl;
        }
    }

    // G(u,v) where u and v are vertices(nodes)
    void addEdge(int u, int weight, int v)
    {
        if(adjMatrix != nullptr)
        {
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight;
        }
        else
        {
            cout<<"Graph doesn't Exist!" <<endl;
        }
    }
    
    void kruskalsAlgorithm()
    {
        Heap h;
        for(int i = 0; i < vertexCount; i++)
        {
            for(int j = i; j < vertexCount; j++)
            {
                if(adjMatrix[i][j] != 0)
                {
                    h.insertEdge(i,adjMatrix[i][j],j);
                }
            }
        }
        
        Edge mst[vertexCount-1];
        int index = -1, mstSum = 0;
        DSU dsu(vertexCount);
        // heap not empty  && |V| - 1 edges
        while(!h.isEmpty() && index < vertexCount-1)
        {
            Edge e = h.deleteEdge();
            if(!dsu.isConnected(e.parent, e.node))
            {
                dsu.Union(e.parent, e.node);
                mstSum = mstSum + e.weight;
                mst[++index] = e;
            }
        }
        
        cout<<"MST Sum: " <<mstSum <<endl;
        cout<<"MST Edges: " <<endl;
        for(int i = 0; i < vertexCount-1; i++)
        {
            cout<<"U: " <<mst[i].parent <<"  Weight: " <<mst[i].weight <<"  V: " <<mst[i].node <<endl;
        }
    }
};

int main()
{
    Graph g(5);
    // g.addEdge(u, weight, v)
    g.addEdge(0,1,3);
    g.addEdge(0,2,4);
    g.addEdge(3,2,2);
    g.addEdge(0,3,1);
    g.addEdge(1,4,3);
    g.addEdge(3,5,4);
    g.addEdge(1,6,2);
    
    g.kruskalsAlgorithm();

    return 0;
}