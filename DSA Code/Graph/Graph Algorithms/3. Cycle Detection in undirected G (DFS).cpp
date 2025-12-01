// Simple and Undirected Graph
#include<iostream>
using namespace std;

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
    void addEdge(int u, int v, int weight = 1)
    {
        if(adjMatrix != nullptr)
        {   
            if(u < vertexCount && u > -1 && v < vertexCount && v > -1)
            {
                adjMatrix[u][v] = weight;
                adjMatrix[v][u] = weight;
            }
            else
            {
                cout<<"Invalid Vertices!" <<endl;
            }
        }
        else
        {
            cout<<"Graph doesn't Exist!" <<endl;
        }
    }

    private:
    bool detect(int currentVertex, int parentVertex, int visitedVertices[])
    {
        visitedVertices[currentVertex] = 1;
        for(int i = 0; i < vertexCount; i++)
        {
            if(adjMatrix[currentVertex][i] != 0 && visitedVertices[i] == 0)
            {
                detect(i, currentVertex, visitedVertices);
            }
            else if(adjMatrix[currentVertex][i] != 0 && i != parentVertex)
            {
                return true;
            }
        }
        return false;
    }

    public:
    bool cycleDetection()
    {
        int visitedVertices[vertexCount];
        for(int i = 0; i < vertexCount; i++)
        {
            visitedVertices[i] = 0;
        }

        for(int i = 0; i < vertexCount; i++)
        {
            if(visitedVertices[i] == 0)
            {
                if(detect(i, -1, visitedVertices))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g(9);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,2);
    
    g.addEdge(4,5);
    g.addEdge(5,6);

    g.addEdge(7,8);

    if(g.cycleDetection())
    {
        cout<<"Cycle Exists!" <<endl;
    }
    else
    {
        cout<<"Cycle Doesn't Exists!" <<endl;
    }
    
    return 0;
}