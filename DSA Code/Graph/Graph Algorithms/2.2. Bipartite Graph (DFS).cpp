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
    bool bipartite(int vertex, int color[], int c)
    {
        // c is color of vertex where 0 means black and 1 means white
        color[vertex] = c;
        for(int i = 0; i < vertexCount; i++)
        {
            if(adjMatrix[vertex][i] != 0 && color[i] == -1)
            {
                if(color[vertex] == 0)
                {
                    return bipartite(i, color, 1);
                }
                else
                {
                    return bipartite(i, color, 0);
                }
            }
            else if(adjMatrix[vertex][i] != 0 && color[vertex] == color[i])
            {
                return false;
            }
        }
        return true;
    }

    public:
    bool bipartiteGraph()
    {
        // color array
        int color[vertexCount];
        for(int i = 0; i < vertexCount; i++)
        {
            // -1 means colorless
            color[i] = -1;
        }

        for(int i = 0; i < vertexCount; i++)
        {
            if(color[i] == -1)
            {
                if(!bipartite(i, color, 0))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2); 
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);

    if(g.bipartiteGraph())
    {
        cout<<"Bipartite Graph!" <<endl;
    }
    else
    {
        cout<<"Not a Bipartite Graph!" <<endl;
    }

    return 0;
}