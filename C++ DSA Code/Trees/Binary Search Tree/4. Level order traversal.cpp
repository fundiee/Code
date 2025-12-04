#include<iostream>
using namespace std;

class TreeNode;

class QueueNode
{
    public:
    QueueNode *next = nullptr;
    TreeNode *address = nullptr;
    QueueNode(TreeNode *address)
    {
        this->address = address;
    }
};

class Queue
{
    QueueNode *front = nullptr;
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

    void enQueue(TreeNode *address)
    {
        if(front == nullptr)
        {
            front = new QueueNode(address);
        }
        else
        {
            QueueNode *temp = front;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new QueueNode(address);
        }
    }
    
    TreeNode* deQueue()
    {
        if(front != nullptr)
        {
            if(front->next == nullptr)
            {
                TreeNode *address = front->address;
                delete front;
                front = nullptr;
                return address;
            }
            else
            {
                TreeNode *address = front->address;
                QueueNode *temp = front;
                front = front->next;
                delete temp;
                return address;
            }
        }
        return nullptr;
    }
};

class TreeNode
{
    public:
    int data;
    TreeNode *left = nullptr, *right = nullptr;
    TreeNode(int data)
    {
        this->data = data;
    }
};

class BST
{
    TreeNode *root = nullptr;
    public:
    BST()
    { }

    void insert(int data)
    {
        root = insert(root, data);
    }
    TreeNode* insert(TreeNode *node, int data)
    {
        if(node == nullptr)
        {
            TreeNode *temp = new TreeNode(data);
            return temp;
        }
        else if(data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void showBST() // level order traversal
    {
        cout<<"BST data: ";
        if(root != nullptr)
        {
            TreeNode *node = root;
            Queue q;
            q.enQueue(node);
            while(!q.isEmpty())
            {
                node = q.deQueue();
                cout<<node->data <<"  ";
                if(node->left != nullptr)
                {
                    q.enQueue(node->left);
                }
                if(node->right != nullptr)
                {
                    q.enQueue(node->right);
                }
            }
        }
        cout<<endl;   
    }
};

int main()
{

    BST t1;
    t1.insert(50);
    t1.insert(30);
    t1.insert(60);
    t1.insert(20);
    t1.insert(40);
    t1.insert(38);
    t1.insert(25);
    t1.insert(55);
    t1.insert(70);
    t1.insert(53);
    t1.insert(80);

    t1.showBST();
    cout<<"--------------------------------------------" <<endl;

    return 0;
}