#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left = nullptr, *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class BST
{
    Node *root = nullptr;
    public:
    BST()
    { }
    void insert(int data)
    {
        root = insert(root, data);
    }
    Node* insert(Node *node, int data)
    {
        if(node == nullptr)
        {
            node = new Node(data);
            return node;
        }
        else if(data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if(data > node->data)
        {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void showBST()
    {
        cout<<"BST data: ";
        showBST(root);
        cout<<endl <<"--------------------------------------------" <<endl;
    }
    void showBST(Node *node)
    {
        if(node != nullptr)
        {
            showBST(node->left);
            cout<<node->data <<"  ";
            showBST(node->right);
        }
    }

    bool searchData(int data) 
    {
        Node *temp = searchData(root, data);
        if(temp != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }    
    }
    Node* searchData(Node *node, int data)
    {
        if(node != nullptr)
        {
            if(node->data == data)
            {
                return node;
            }
            else if(data < node->data)
            {
                return searchData(node->left,data);
            }
            else
            {
                return searchData(node->right,data);
            }
        }
        else
        {
            return node;
        }
    }

    int countTotalNodes()
    {
        return countTotalNodes(root);
    }
    int countTotalNodes(Node *node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        return countTotalNodes(node->left) + countTotalNodes(node->right) + 1;
    }
    
    // returns InOrder Predecessor case 1
    int predecessorValue(Node *node)
    {
        if(node->right == nullptr)
        {
            return node->data;
        }
        return predecessorValue(node->right);
    }

    /*
    // returns InOrder Successor case 1
    int successorValue(Node *node)
    {
        if(node->left == nullptr)
        {
            return node->data;
        }
        return successorValue(node->left);
    }
    */

    void deleteNode(int data)
    {
        root = deleteNode(root, data);
    }
    Node* deleteNode(Node *node, int data)
    {
        if(node != nullptr)
        {
            if(node->data == data) 
            {
                // node having no child (leaf node)
                if(node->left == nullptr && node->right == nullptr) 
                {
                    delete node;
                    return nullptr;
                }
                // node having only left child
                else if(node->left != nullptr && node->right == nullptr)
                {
                    Node *temp = node->left;
                    delete node;
                    return temp;
                }
                // node having only right child
                else if(node->right != nullptr && node->left == nullptr)
                {
                    Node *temp = node->right;
                    delete node;
                    return temp;
                }
                // node having two childs
                else
                {
                // InOrder predecessor Implementation
                    // InOrder Predecessor case 1
                    if(node->left->right != nullptr) 
                    {
                        node->data = predecessorValue(node->left);
                        deleteNode(node->left, node->data);
                    }
                    // InOrder Predecessor case 2 i.e if (node->left->right == nullptr)
                    else  
                    {
                        node->left->right = node->right;
                        Node *temp = node->left;
                        delete node;
                        return temp;
                    }
                    
                    /*
                // InOrder Successor Implementation
                    // InOrder Successor case 1
                    if(node->right->left != nullptr) 
                    {
                        node->data = successorValue(node->right);
                        deleteNode(node->right, node->data);
                    }
                    // InOrder Successor case 2 i.e if node->right->left == nullptr
                    else
                    {
                        node->right->left = node->left;
                        Node *temp = node->right;
                        delete node;
                        return temp;
                    }
                    */
                }
            }
            else if(data < node->data)
            {
                node->left = deleteNode(node->left, data);
            }
            else if(data > node->data)
            {
                node->right = deleteNode(node->right, data);
            }
        }
        return node;
    }

    // it can also handle double free
    void deleteBST() 
    {
        deleteBST(root);
        root = nullptr;
    }
    void deleteBST(Node *node)
    {
        if(node != nullptr)
        {
            deleteBST(node->left);
            deleteBST(node->right);
            delete node;
        }
    }

    ~BST()
    {
        deleteBST(root);
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

    t1.deleteNode(38);
    t1.showBST();

    t1.deleteNode(55);
    t1.showBST();
    
    t1.deleteNode(50);
    t1.showBST();

    t1.deleteNode(60);
    t1.showBST();

    if(t1.searchData(53))
    {
        cout<<"Data found!" <<endl;
    }
    else
    {
        cout<<"Data not found!" <<endl;
    }
    cout<<"--------------------------------------------" <<endl;

    cout<<"Total nodes: " <<t1.countTotalNodes() <<endl;
    
    // Binary Search Tree Deleted
    t1.deleteBST();
    t1.showBST();
    
    return 0;
}