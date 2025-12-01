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

// class Queue is implemented for BFS
class Queue
{
    Node *front = nullptr;
    public:
    Queue()
    { }

    bool isEmpty()
    {
        if(front == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enQueue(int data)
    {
        if(front == nullptr)
        {
            front = new Node(data);
        }
        else
        {
            Node *temp = front;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node(data);
        }
    }

    int deQueue()
    {
        if(front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            int deQueuedElement = temp->data;
            delete temp;
            return deQueuedElement;
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

    void removeEdge(int u, int v)
    {
        if(u > -1 && u < vertexCount && v > -1 && v < vertexCount)
        {
            adjMatrix[u][v] = 0;
        }
        else
        {
            cout<<"Invalid Vertices!" <<endl;
        }
    }

    void printAdjMatrix()
    {
        cout<<"----------Adjacent Vertices of Graph----------" <<endl;
        for(int rows = 0; rows < vertexCount; rows++)
        {
            cout<<"Vertex[" <<rows <<"]:" <<endl;;
            for(int columns = 0; columns < vertexCount; columns++)
            {
                if(adjMatrix[rows][columns] != 0)
                {
                    // ordered pair(undirected)
                    cout<<"[" <<rows <<"," <<columns <<"]" <<"   " <<endl;
                }
            }
            cout<<"---------------------------------------------" <<endl;
        }
    }

    void hasEdge(int u, int v)
    {
        if(u < vertexCount && u > -1 && v < vertexCount && v > -1)
        {
            if(adjMatrix[u][v] != 0)
            {
                cout<<"Edge Exists!" <<endl;
            }
            else
            {
                cout<<"Edge Doesn't Exists!" <<endl;
            }
        }
        else
        {
            cout<<"Invalid Vertices!" <<endl;
        }
    }

    private:
    void BFS(int vertex, int visitedVertices[])
    {
        Queue q;
        q.enQueue(vertex);
        visitedVertices[vertex] = 1;
        while(!q.isEmpty())
        {
            int visitedVertex = q.deQueue();
            cout<<visitedVertex <<"  ";
            // Exploration of all adjacent vertices
            for(int i = 0; i < vertexCount; i++)
            {
                // existance of adjacent vertex        &&    vertex is not visited
                if(adjMatrix[visitedVertex][i] == 1    &&    visitedVertices[i] == 0)
                {
                    q.enQueue(i);
                    visitedVertices[i] = 1;
                }
            }
        }
    }


    public:
    void BFSTraversal()
    {
        int visitedVertices[vertexCount];
        for(int i = 0; i < vertexCount; i++)
        {
            visitedVertices[i] = 0;
        }

        cout<<"BFS: ";
        for(int i = 0; i < vertexCount; i++)
        {
            if(visitedVertices[i] == 0)
            {
                BFS(i, visitedVertices);
            }
        }
        cout<<endl <<"---------------------------------------------" <<endl;;
    }

    private:
    void postDFS(int vertex, int visitedVertices[])
    {
        visitedVertices[vertex] = 1;
        for(int i = 0; i < vertexCount; i++)
        {
            if(adjMatrix[vertex][i] == 1 && visitedVertices[i] == 0)
            {
                postDFS(i,visitedVertices);
            }
        }
        cout<<vertex <<"  ";
    }

    public:
    void postOrderDFS()
    {
        int visitedVertices[vertexCount];
        for(int i = 0; i < vertexCount; i++)
        {
            visitedVertices[i] = 0;
        }

        cout<<"Post Order DFS: ";
        for(int i = 0; i < vertexCount; i++)
        {
            if(visitedVertices[i] == 0)
            {
                postDFS(i, visitedVertices);
            }
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
    g.BFSTraversal();
    g.postOrderDFS();

    return 0;
}