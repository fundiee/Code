// Simple and Undirected Graph
#include<iostream>
using namespace std;

// class Node is implemented for both classes Queue and Stack
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

class Vertex
{
    public:
    int vertexNum;
    Vertex *next = nullptr;
    Vertex(int vertexNum)
    {
        this->vertexNum = vertexNum;
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

    void addEdge(int u, int v)
    {
        if(adjList != nullptr)
        {
            if(u < vertexCount && u > -1 && v < vertexCount && v > -1)
            {
                int temp = 1;
                do
                {
                    if(adjList[u] == nullptr)
                    {
                        adjList[u] = new Vertex(v);
                    }
                    else
                    {
                        Vertex *temp = adjList[u];
                        while(temp->next != nullptr)
                        {
                            temp = temp->next;
                        }
                        temp->next = new Vertex(v);
                    }
                    // edge for vertex u is inserted, now add edge for vertex v
                    int swap = u;
                    u = v;
                    v = swap;
                    temp++;
                } while(temp <= 2);
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

    void removeEdge(int u, int v)
    {
        if(adjList != nullptr)
        {
            if(u < vertexCount && u > -1 && v < vertexCount && v > -1)
            {
                int temp = 1;
                do
                {
                    if(adjList[u] != nullptr)
                    {
                        if(adjList[u]->next == nullptr)
                        {
                            if(adjList[u]->vertexNum == v)
                            {
                                delete adjList[u];
                                adjList[u] = nullptr;
                            }
                            else
                            {
                                cout<<"No Adjacent vertex exists!" <<endl;
                            }
                        }
                        else
                        {
                            if(adjList[u]->vertexNum == v)
                            {
                                Vertex *temp = adjList[u];
                                adjList[u] = adjList[u]->next;
                                delete temp;
                            }
                            else
                            {
                                // Searching logic
                                Vertex *temp = adjList[u];
                                while(temp->next != nullptr)
                                {
                                    if(temp->next->vertexNum == v)
                                    {
                                        break;
                                    }
                                    temp = temp->next;
                                }
                                // Two cases: Vertex found or last vertex checking in adjList
                                if(temp->next->vertexNum == v)
                                {
                                    Vertex *delVertex = temp->next;
                                    temp->next = temp->next->next;
                                    delete delVertex;
                                }
                                else
                                {
                                    cout<<"No Adjacent vertex exist!" <<endl;
                                }
                            }
                        }
                    }
                    else
                    {
                        cout<<"Isolated Vertex, no edges exists!" <<endl;
                        break;
                    }
                    int swap = u;
                    u = v;
                    v = swap;
                    temp++;
                } while(temp <= 2);
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

    void hasEdge(int u, int v)
    {
        if(adjList != nullptr)
        {
            if(u < vertexCount && u > -1 && v < vertexCount && v > -1)
            {
                if(adjList[u] != nullptr)
                {
                    Vertex *temp = adjList[u];
                    while(temp != nullptr)
                    {
                        if(temp->vertexNum == v)
                        {
                            cout<<"Edge exist!" <<endl;
                            return;
                        }
                        temp = temp->next;
                    }
                    cout<<"Edge doesn't exist!" <<endl;
                }
                else
                {
                    cout<<"Isolated verted, so no edges exists!" <<endl;
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

    void printAdjList()
    {
        if(adjList != nullptr)
        {
            cout<<"----------Adjacency List-----------" <<endl;
            for(int i = 0; i < vertexCount; i++)
            {
                Vertex *temp = adjList[i];
                cout<<"vertex[" <<i <<"]: ";
                while(temp != nullptr)
                {
                    cout<<temp->vertexNum <<"  ";
                    temp = temp->next;
                }
                cout<<endl;
            }
            cout<<"-----------------------------------" <<endl;
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
            Vertex *temp = adjList[visitedVertex];
            while(temp != nullptr)
            {
                int adjacentVertex = temp->vertexNum;
                // vertex is not visited
                if(visitedVertices[adjacentVertex] == 0)
                {
                    q.enQueue(adjacentVertex);
                    visitedVertices[adjacentVertex] = 1;
                }
                temp = temp->next;
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
        Vertex *temp = adjList[vertex];
        while(temp != nullptr)
        {
            if(visitedVertices[temp->vertexNum] == 0)
            {
                preDFS(temp->vertexNum, visitedVertices);
            }
            temp = temp->next;
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
        cout<<endl <<"---------------------------------------------" <<endl;;
    }

    private:
    void postDFS(int vertex, int visitedVertices[])
    {
        visitedVertices[vertex] = 1;
        Vertex *temp = adjList[vertex];
        while(temp != nullptr)
        {
            if(visitedVertices[temp->vertexNum] == 0)
            {
                postDFS(temp->vertexNum, visitedVertices);
            }
            temp = temp->next;
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
        if(adjList != nullptr)
        {
            for(int i = 0; i < vertexCount; i++)
            {
                Vertex *temp = adjList[i];
                Vertex *delNode = temp;
                while(temp != nullptr)
                {
                    temp = temp->next;
                    delete delNode;
                    delNode = temp;
                }
            }
            delete []adjList;
            adjList = nullptr;
        }
    }

    void createGraph(int vertexCount)
    {
        if(adjList == nullptr)
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
                cout<<"Graph is not created!" <<endl;
            }

        }
        else
        {
            cout<<"Invalid operation, Graph already exist!" <<endl;
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
    g.addEdge(0,3);
    g.addEdge(0,4);
    //g.addEdge(1,2);
    g.addEdge(1,3);
    //g.addEdge(2,3);
    g.addEdge(4,3);

    g.printAdjList();
    g.BFSTraversal();
    g.preOrderDFS();
    g.postOrderDFS();

    g.removeEdge(0,3);
    g.removeEdge(1,3);
    g.printAdjList();

    // Invalid Vertices
    g.hasEdge(5,1);
    cout<<"---------------------------------------------" <<endl;

    // Invalid operation because Graph already exist for this object!
    g.createGraph(7);
    cout<<"---------------------------------------------" <<endl;

    g.deleteGraph();
    // Graph doesn't exist!
    g.printAdjList();
    cout<<"---------------------------------------------" <<endl;

    g.createGraph(7);
    // no edges or no adjacent vertices
    g.printAdjList();

    return 0;
}