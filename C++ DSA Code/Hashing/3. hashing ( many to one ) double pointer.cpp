// Many to One Function, so collision occurs. Collision Resolution (chaining)
#include <iostream>
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

class Hashing
{
    Node **array = nullptr;
    int size;
    public:
    Hashing(int size)
    {
        this->size = size;
        array = new Node*[size];
        for(int i = 0; i < size; i++)
        {
            array[i] = nullptr;
        }
    }
    
    int hashFunction(int key)
    {
        return key%size;
    }
    
    void insertElement(int data)
    {
        if(array != nullptr)
        {
            int index = hashFunction(data);
            if(array[index] == nullptr)
            {
                array[index] = new Node(data);
            }
            else
            {
                Node *temp = array[index];
                while(temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = new Node(data);
            }
        }
        else
        {
            cout<<"Hash Table doesn't exist!" <<endl;
        }
    }

    void searchElement(int data)
    {
        if(array != nullptr)
        {
            int index = hashFunction(data);
            if(array[index] != nullptr)
            {
                Node *temp = array[index];
                while(temp != nullptr)
                {
                    if(temp->data == data)
                    {
                        cout<<"Data found!" <<endl;
                        return;
                    }
                    temp = temp->next;
                }
                cout<<"Data not found!" <<endl;
            }
            else
            {
                cout<<"Data doesn't Exist!" <<endl;
            }
        }
        else
        {
            cout<<"Hash Table doesn't Exist!" <<endl;
        }
    }
     

    void show()
    {
        if(array != nullptr)
        {
            cout<<"-----------Hash Table-----------" <<endl;
            for(int i = 0; i < size; i++)
            {
                Node *temp = array[i];
                // condition to remove empty spaces of endl
                if(temp == nullptr)
                {
                    continue;
                }
                while(temp != nullptr)
                {
                    cout<<temp->data <<"  ";
                    temp = temp->next;
                }
                cout<<endl;
            }
            cout<<"-------------------------------" <<endl;
        }
        else
        {
            cout<<"Hash Table doesn't exist!" <<endl;
        }
    }

    // helper function for deleteElement function
    Node* searchNode(Node *node,int data)
    {
        if(node != nullptr)
        {
            while(node != nullptr)
            {
                if(node->data == data)
                {
                    return node;
                }
                node = node->next;
            }
        }
        return node;
    }

    void deleteElement(int data)
    {
        if(array != nullptr)
        {
            int index = hashFunction(data);
            Node *delNode = searchNode(array[index],data);
            if(delNode != nullptr)
            {
                if(delNode == array[index])
                {
                    array[index] = array[index]->next;
                    delete delNode;
                }
                else
                {
                    Node *temp = array[index];
                    while(temp->next != delNode)
                    {
                        temp = temp->next;
                    }
                    temp->next = temp->next->next;
                    delete delNode;
                }
            }
            else
            {
                cout<<"Data doesn't exist!" <<endl;
            }
        }
        else
        {
            cout<<"Hash Table doesn't exist!" <<endl;
        }
    }

    void deleteHashTable()
    {
        if(array != nullptr)
        {
            for(int i = 0; i < size; i++)
            {
                Node *temp = array[i];
                while(temp != nullptr)
                {
                    array[i] = array[i]->next;
                    delete temp;
                    temp = array[i];
                }
            }
            delete []array;
            array = nullptr;
        }
    }

    void createHashTable(int size)
    {
        if(array == nullptr)
        {
            this->size = size;
            array = new Node*[size];
            for(int i = 0; i < size; i++)
            {
                array[i] = nullptr;
            }
        }
        else
        {
            cout<<"Invalid Operation! Hash Table already exist!" <<endl;
        }
    }

    ~Hashing()
    {
        deleteHashTable();
    }
    
};

int main()
{
    Hashing h(5);
    h.insertElement(33);
    h.insertElement(49);
    h.insertElement(57);
    h.insertElement(66);
    h.insertElement(61);
    h.insertElement(93);
    h.insertElement(102);
    h.insertElement(107);
    h.insertElement(123);
    h.insertElement(109);
    h.insertElement(172);
    h.insertElement(20);

    h.show();

    h.deleteElement(61);
    h.deleteElement(20);
    h.deleteElement(107);
    h.deleteElement(123);
    h.deleteElement(49);
    h.show();

    h.createHashTable(10);
    cout<<"-------------------------------" <<endl;

    h.deleteHashTable();
    h.show();
    
    h.createHashTable(10);
    h.insertElement(10);
    h.insertElement(14);
    h.insertElement(15);
    h.insertElement(25);
    h.insertElement(19);
    h.show();

    return 0;
}