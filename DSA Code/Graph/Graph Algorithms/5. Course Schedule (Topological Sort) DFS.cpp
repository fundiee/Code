#include<iostream>
using namespace std;

// class Node is implemented for both classes Queue and stack
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


// class Stack is implemented for DFS
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


class DiGraph
{
    int **adjMatrix = nullptr;
    int vertexCount;
    Stack reversedDFSPostOrder;
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

    private:
    void postDFS(int vertex, int visitedVertices[])
    {
        visitedVertices[vertex] = 1;
        for(int i = 0; i < vertexCount; i++)
        {
            if(adjMatrix[vertex][i] != 0 && visitedVertices[i] == 0)
            {
                postDFS(i,visitedVertices);
            }
        }
        reversedDFSPostOrder.push(vertex);
    }

    public:
    void topologicalSort()
    {
        if(cycleDetection())
        {
            cout<<"Topological Sort not possible due to cycle existed in Di-Graph! " <<endl;
            return;
        }

        int visitedVertices[vertexCount];
        for(int i = 0; i < vertexCount; i++)
        {
            visitedVertices[i] = 0;
        }
        
        for(int i = 0; i < vertexCount; i++)
        {
            if(visitedVertices[i] == 0)
            {
                postDFS(i, visitedVertices);
            }
        }

        cout<<"Topological Sort: ";
        while(!reversedDFSPostOrder.isEmpty())
        {
            cout<<reversedDFSPostOrder.pop() <<"  ";
        }
        cout<<endl <<"---------------------------------------------" <<endl;;
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
    g.topologicalSort();

    return 0;
}