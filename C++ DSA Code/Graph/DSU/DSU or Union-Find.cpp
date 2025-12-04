// DSU or Union-Find
#include<iostream>
using namespace std;

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
    
    // Just for testing DSU
    void test()
    {
        for(int i = 0; i < capacity; i++)
        {
            cout<<parent[i] <<"  ";
        }
    }
    
    ~DSU()
    {
        delete []parent;
        parent = nullptr;
        delete []rootSize;
        rootSize = nullptr;
    }
};

int main()
{
    DSU dsu(10);
    dsu.Union(0,6);
    dsu.Union(4,5);
    dsu.Union(3,4);
    dsu.Union(2,0);
    dsu.Union(3,4);
    dsu.Union(6,7);
    dsu.Union(1,4);
    dsu.Union(3,9);
    dsu.Union(2,7);
    dsu.Union(3,6);
    dsu.Union(2,8);
    
    dsu.test();

    return 0;
}