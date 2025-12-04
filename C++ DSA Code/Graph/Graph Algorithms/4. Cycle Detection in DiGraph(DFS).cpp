// Cycle Detection in Directed Graph using DFS
#include<iostream>
using namespace std;

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

    private:
    bool detect(int vertex, int visitedVertices[], int pathVisited[])
    {
        visitedVertices[vertex] = 1;
        pathVisited[vertex] = 1;

        for(int i = 0; i < vertexCount; i++)
        {
            if(adjMatrix[vertex][i] != 0 && visitedVertices[i] == 0)
            {
                // if true then recursively true is returned no false returns in any call
                if(detect(i, visitedVertices, pathVisited) == true)
                {
                    return true;
                }
            }
            else if(adjMatrix[vertex][i] != 0 && visitedVertices[i] == 1 && pathVisited[i] == 1)
            {
                return true;
            }
        }
        pathVisited[vertex] = 0;
        // for each call false is returned if true not returned
        return false;
    }

    public:
    bool cycleDetection()
    {
        int visitedVertices[vertexCount];
        int pathVisited[vertexCount];

        for(int i = 0; i < vertexCount; i++)
        {
            visitedVertices[i] = 0;
            pathVisited[i] = 0;
        }

        for(int i = 0; i < vertexCount; i++)
        {
            if(visitedVertices[i] == 0)
            {
                if(detect(i, visitedVertices, pathVisited))
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
    DiGraph g(7);
    // Direct Acyclic Graph (DAG) edges
    
    g.addEdge(0,5);
    g.addEdge(0,2);
    g.addEdge(0,1);
    g.addEdge(3,6);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.addEdge(5,2);
    g.addEdge(6,4);
    g.addEdge(6,0);
    g.addEdge(3,2);
    g.addEdge(1,4);

    if(g.cycleDetection())
    {
        cout<<"Cycle exists in Graph!" <<endl;
    }
    else
    {
        cout<<"Cycle doesn't exists in Graph!" <<endl;
    }

    return 0;
}