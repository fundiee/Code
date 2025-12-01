#include<iostream>
using namespace std;

class Node
{
    public:
    int item;
    Node *next = nullptr;
    Node(int item)
    {
        this->item = item;
    }
};

class Stack
{
    Node *top = nullptr;
    public:

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

    void push(int item)
    {
        if(top == nullptr)
        {
            top = new Node(item);
        }
        else
        {
            Node *temp = new Node(item);
            temp->next = top;
            top = temp;
        }
    }

    int pop()
    {
        if(top != nullptr)
        {
            int topElement = top->item;
            Node *temp = top;
            top = top->next;
            delete temp;
            return topElement;
        }
        else
        {
            cout<<"Stack is Underflow!";
            return -1;
        }
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

    private:
    void postDFS(int vertex, int visitedVerices[], Stack &finishTime)
    {
        visitedVerices[vertex] = 1;

        for(int i = 0; i < vertexCount; i++)
        {
            if(adjMatrix[vertex][i] != 0 && visitedVerices[i] == 0)
            {
                postDFS(i, visitedVerices, finishTime);
            }
        }
        finishTime.push(vertex);
    }

    void preDFS(int vertex, int **reversedGraph ,int visitedVertices[], int scc[], int sccCount)
    {
        visitedVertices[vertex] = 1;
        scc[vertex] = sccCount;

        for(int i = 0; i < vertexCount; i++)
        {
            if(reversedGraph[vertex][i] != 0 && visitedVertices[i] == 0)
            {
                preDFS(i, reversedGraph, visitedVertices, scc, sccCount);
            }
        }
    }

    public:
    void stronglyConnectedComponents()
    {
        int visitedVertices[vertexCount];
        for(int i = 0; i < vertexCount; i++)
        {
            visitedVertices[i] = 0;
        }

        Stack finishTime;

        for(int i = 0; i < vertexCount; i++)
        {
            if(visitedVertices[i] == 0)
            {
                postDFS(i, visitedVertices, finishTime);
            }
        }

        int **reversedGraph = new int*[vertexCount];
        for(int i = 0; i < vertexCount; i++)
        {
            reversedGraph[i] = new int[vertexCount];
        }
        // O(n square) because of adjMatrix data structure so, adjList is far better
        for(int u = 0; u < vertexCount; u++)
        {
            for(int v = 0; v < vertexCount; v++)
            {
                if(adjMatrix[u][v] == 1)
                {
                    reversedGraph[v][u] = adjMatrix[u][v];
                }
                else
                {
                    reversedGraph[v][u] = 0;
                }
            }
        }


        for(int i = 0; i < vertexCount; i++)
        {
            visitedVertices[i] = 0;
        }

        int top, sccCount = 0;
        int scc[vertexCount];
        while(!finishTime.isEmpty())
        {
            top = finishTime.pop();
            if(visitedVertices[top] == 0)
            {
                sccCount++;
                preDFS(top, reversedGraph, visitedVertices, scc, sccCount);
            }
        }
        
        cout<<"Total Strongly Connected Components: " <<sccCount << endl <<endl;
        for(int initailComponent = 1; initailComponent <= vertexCount; initailComponent++)
        {
            for(int index = 0; index < vertexCount; index++)
            {
                if(scc[index] == initailComponent)
                {
                    cout<<index <<"  ";
                }
            }
            cout<<endl <<endl;
        }
        cout<<endl;
    }
    
};

int main()
{

    DiGraph g(9);
    
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,0);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,4);
    g.addEdge(7,8);
    g.stronglyConnectedComponents();    

    return 0;
}