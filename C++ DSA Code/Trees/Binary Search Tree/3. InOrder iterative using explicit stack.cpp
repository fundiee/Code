#include<iostream>
using namespace std;

class TreeNode;

class StackNode
{
    public:
    StackNode *next = nullptr;
    TreeNode *address = nullptr;
    StackNode(TreeNode *node)
    {
        address = node;
    }
};

class Stack
{
    public:
    StackNode *top = nullptr;
    void push(TreeNode *node)
    {
        if(top == nullptr)
        {
            top = new StackNode(node);
        }
        else
        {
            StackNode *temp = new StackNode(node);
            temp->next = top;
            top = temp;
        }
    }

    TreeNode* pop()
    {
        if(top != nullptr)
        {
            TreeNode *address = top->address;
            StackNode *temp = top;
            top = top->next;
            delete temp;
            return address;
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

void showBST()
{
    cout<<"BST Data: ";
    if(root != nullptr)
    {
        TreeNode *node = root;
        Stack *s = new Stack;
        while(node != nullptr || s->top != nullptr)
        {
            if(node != nullptr)
            {
                s->push(node);
                node = node->left;
            }
            else
            {
                node = s->pop();
                cout<<node->data <<"  ";
                node = node->right;
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