// Simple and Undirected Graph
#include<iostream>
using namespace std;

// class Node is implemented for Queue
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

    void removeEdge(int u, int v)
    {
        if(adjMatrix != nullptr)
        {
            if(u < vertexCount && u > -1 && v < vertexCount && v > -1)
            {
                adjMatrix[u][v] = 0;
                adjMatrix[v][u] = 0;
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

    void hasEdge(int u, int v)
    {
        if(adjMatrix != nullptr)
        {
            if(u < vertexCount && u > -1 && v < vertexCount && v > -1)
            {
                if(adjMatrix[u][v] != 0 && adjMatrix[v][u] != 0)
                {
                    cout<<"Edge exists because given vertices are adjacent!" <<endl;
                }
                else
                {
                    cout<<"Edge not exists because given vertices are not adjacent!" <<endl;
                }
            }
            else
            {
                cout<<"Invalid Vertices" <<endl;
            }
        }
        else
        {
            cout<<"Graph doesn't Exist!" <<endl;
        }
    }

    void printAdjMatrix()
    {
        if(adjMatrix != nullptr)
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
            }
            cout<<"---------------------------------------------" <<endl;
        }
        else
        {
            cout<<"Graph doesn't exist!" <<endl;
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
    void preDFS(int vertex, int visitedVertices[])
    {
        visitedVertices[vertex] = 1;
        cout<<vertex <<"  ";
        for(int i = 0; i < vertexCount; i++)
        {
            if(adjMatrix[vertex][i] == 1 && visitedVertices[i] == 0)
            {
                preDFS(i,visitedVertices);
            }
        }
    }

    public:
    void preOrderDFS()
    {
        int visitedVertices[vertexCount];
        for(int i = 0; i < vertexCount; i++)
        {
            visitedVertices[i] = 0;
        }

        cout<<"Pre Order DFS: ";

        for(int i = 0; i < vertexCount; i++)
        {
            if(visitedVertices[i] == 0)
            {
                preDFS(i, visitedVertices);
            }
        }
        cout<<endl <<"---------------------------------------------" <<endl;
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

    void deleteGraph()
    {
        if(adjMatrix != nullptr)
        {
            for(int rows = 0; rows < vertexCount; rows++)
            {
                delete []adjMatrix[rows];
            }
            delete []adjMatrix;
            adjMatrix = nullptr;
            vertexCount = -1;
        }
    }

    void createGraph(int vertexCount)
    {
        if(adjMatrix == nullptr)
        {
            if(vertexCount > 0)
            {
                this->vertexCount = vertexCount;
                adjMatrix = new int*[vertexCount];
                for(int rows = 0; rows < vertexCount; rows++)
                {
                    adjMatrix[rows] = new int[vertexCount];
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
        else
        {
            cout<<"Invalid Operation! Graph already exists!" <<endl;
        }
    }

    ~Graph()
    {
        deleteGraph();
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    //g.addEdge(1,2);
    //g.addEdge(2,3);
    g.addEdge(1,3);
    g.addEdge(4,3);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.printAdjMatrix();
    g.BFSTraversal();
    g.preOrderDFS();
    g.postOrderDFS();

    g.removeEdge(0,3);
    g.removeEdge(1,3);
    g.printAdjMatrix();

    // Invalid Vertices
    g.hasEdge(5,1);
    cout<<"---------------------------------------------" <<endl;

    // Invalid operation because Graph already exist for this object!
    g.createGraph(7);
    cout<<"---------------------------------------------" <<endl;

    g.deleteGraph();
    // Graph doesn't exist!
    g.printAdjMatrix();
    cout<<"---------------------------------------------" <<endl;

    g.createGraph(7);
    // no edges or no adjacent vertices
    g.printAdjMatrix();

    return 0;
}