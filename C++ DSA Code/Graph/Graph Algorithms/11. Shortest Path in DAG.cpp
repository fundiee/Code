#include<iostream>
using namespace std;

class Edge
{
    public:
    int parent, u;
};

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

    int peak()
    {
        if(top != nullptr)
        {
            return top->data;
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

    bool topologicalSort()
    {
        if(cycleDetection())
        {
            cout<<"Not a Directed Acyclic Graph(DAG)! " <<endl;
            return true;
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
        
        return false;
    }

    public:
    void shortestPathDAG(int sink)
    {
        if(topologicalSort())
        {
            // returns if not a DAG!
            return;
        }

        int *totalDistTo = new int[vertexCount];
        Edge *edgeTo = new Edge[vertexCount];
        for(int i = 0; i < vertexCount; i++)
        {
            totalDistTo[i] = INT32_MAX;

            edgeTo[i].parent = i;
            edgeTo[i].u = i;
        }

        int source = reversedDFSPostOrder.peak();
        totalDistTo[source] = 0;
        while(!reversedDFSPostOrder.isEmpty())
        {
            int u = reversedDFSPostOrder.pop();
            for(int v = 0; v < vertexCount; v++)
            {
                if(adjMatrix[u][v] != 0)
                {
                    if(totalDistTo[u] + adjMatrix[u][v] < totalDistTo[v])
                    {
                        totalDistTo[v] = totalDistTo[u] + adjMatrix[u][v];
                        edgeTo[v].parent = u;
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

        // free memory resources
        delete[] totalDistTo,edgeTo;
        totalDistTo = nullptr, edgeTo = nullptr;
    }
};

int main()
{
    DiGraph g(5);
    // u,v,weight
    g.addEdge(0,1,4);
    g.addEdge(0,3,2);
    g.addEdge(0,4,9);
    g.addEdge(1,2,1);
    g.addEdge(3,1,1);
    g.addEdge(3,2,6);
    g.addEdge(3,4,3);

    g.shortestPathDAG(2);

    return 0;
}