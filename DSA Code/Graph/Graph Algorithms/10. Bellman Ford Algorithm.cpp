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
    int p, w, v;
};

class Vertex
{
    public:
    int v, w;
    Vertex *next = nullptr;
    Vertex(int vertex, int weight)
    {
        this->v = vertex;
        this->w = weight;
    }
};

class Graph
{
    Vertex **adjList = nullptr;
    int vertexCount;
    public:
    Graph(int vertexCount)
    {
        if(vertexCount > 0)
        {
            this->vertexCount = vertexCount;
            adjList = new Vertex*[vertexCount];
            for(int i = 0; i < vertexCount; i++)
            {
                adjList[i] = nullptr;
            }
        }
        else
        {
            cout<<"Graph is not Created!" <<endl;
        }
    }

    void addEdge(int u, int w, int v)
    {
        if(adjList != nullptr)
        {
            if(u < vertexCount && u > -1 && v < vertexCount && v > -1)
            {
                if(adjList[u] == nullptr)
                {
                    adjList[u] = new Vertex(v, w);
                }
                else
                {
                    Vertex *temp = adjList[u];
                    while(temp->next != nullptr)
                    {
                        temp = temp->next;
                    }
                    temp->next = new Vertex(v, w);
                }
            }
            else
            {
                cout<<"Invalid vertices!" <<endl;
            }
        }
        else
        {
            cout<<"Graph doesn't exist!" <<endl;
        }
    }

    void bellmanFord(int sink)
    {
        if(sink < 0)
        {
            cout<<"Invalid Sink!" <<endl;
            return;
        }
        
        Edge edgeTo[vertexCount];
        int totalDistTo[vertexCount];

        for(int i = 1; i < vertexCount; i++)
        {
            totalDistTo[i] = INT32_MAX;
        }

        // totalDistT0[source] = 0
        totalDistTo[0] = 0;
        edgeTo[0].p = 0;
        edgeTo[0].w = 0;
        edgeTo[0].v = 0;
        
        // |V| - 1 times relaxation 
        for(int i = 1; i < vertexCount; i++)
        {
            for(int u = 0; u < vertexCount; u++)
            {
                Vertex *temp = adjList[u];
                while(temp != nullptr)
                {
                    // Relaxation
                    if(totalDistTo[u] + temp->w < totalDistTo[temp->v])
                    {
                        totalDistTo[temp->v] = totalDistTo[u] + temp->w;
                        edgeTo[temp->v].p = u;
                        edgeTo[temp->v].v = temp->v;
                        edgeTo[temp->v].w = totalDistTo[temp->v];
                    }
                    temp = temp->next;
                }
            }
        }

        // Negative weighted cycle detection and shortest path correctness test
        for(int u = 0; u < vertexCount; u++)
        {
            Vertex *temp = adjList[u];
            while(temp != nullptr)
            {
                // Relaxation
                if(totalDistTo[u] + temp->w < totalDistTo[temp->v])
                {
                    cout<<"Negative weighted cycle existed in graph, so shortest path is not possible!" <<endl;
                    return;
                }
                temp = temp->next;
            }
        }

        Stack s;
        for(int i = sink; i > 0; i = edgeTo[i].p)
        {
            s.push(i);
        }
        s.push(0);

        cout<<"Shortest path from 0 to " <<sink <<" : ";
        while(!s.isEmpty())
        {
            cout<<s.pop() <<"  ";
        }
        cout<<endl <<"Total Distance: " <<totalDistTo[sink] <<endl;
        cout<<"---------------------------------------------" <<endl;


    }
};

int main()
{
    Graph g(7);

    //        u, w, v
    g.addEdge(0, 6, 1);
    g.addEdge(0, 5, 2);
    g.addEdge(0, 5, 3);
    g.addEdge(1,-1, 4);
    g.addEdge(2,-2, 1);
    g.addEdge(2, 1, 4);
    g.addEdge(3,-2, 2);
    g.addEdge(3,-1, 5);
    g.addEdge(4, 3, 6);
    g.addEdge(5, 3, 6);

    g.bellmanFord(6);

    return 0;
}