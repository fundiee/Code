#include<iostream>
using namespace std;

class Node
{
    public:
    int data, height;
    Node *left = nullptr, *right = nullptr;
    Node(int data)
    {
        this->data = data;
        // leaf node height = 1, implementation of tree height 1 onwards
        height = 1;
    }
};

class AVL
{
    Node *root = nullptr;
    public:
    AVL()
    { }
    
    int nodeHeight(Node *node)
    {
        int hl, hr;
        if(node != nullptr)
        {
            if(node->left != nullptr)
            {
                hl = node->left->height;
            }
            else
            {
                hl = 0;
            }

            if(node->right != nullptr)
            {
                hr = node->right->height;
            }
            else
            {
                hr = 0;
            }

            // height = greater subtree + 1
            if(hl > hr)
            {
                return hl+1;
            }
            else
            {
                return hr+1;
            }
        }
        else
        {
            return 0;
        }
    }

    int balanceFactor(Node *node)
    {
        int hl, hr;
        if(node != nullptr)
        {
            if(node->left != nullptr)
            {
                hl = node->left->height;
            }
            else
            {
                hl = 0;
            }

            if(node->right != nullptr)
            {
                hr = node->right->height;
            }
            else
            {
                hr = 0;
            }
            // balance factor = height of left sub-tree - height of right sub-tree
            return hl-hr;
        }
        else
        {
            return 0;
        }
    }

    Node* LLRotation(Node *node)
    {
        // saved node addresses
        Node *nodeLeft = node->left;
        Node *nodeLeftRight = node->left->right;

        // perform  rotation
        nodeLeft->right = node;
        node->left = nodeLeftRight;

        // update height ( using node's height properties not recursively )
        node->height = nodeHeight(node);
        nodeLeft->height = nodeHeight(nodeLeft);
        // return new root after rotation
        return nodeLeft;
    }

    Node* LRRotation(Node *node)
    {
        // save nodes addresses
        Node *nodeLeftRight = node->left->right;
        Node *nodeLeftRightLeft = node->left->right->left;
        Node *nodeLeftRightRight = node->left->right->right;

        // perform rotation
        nodeLeftRight->left = node->left;
        nodeLeftRight->right = node;
        nodeLeftRight->left->right = nodeLeftRightLeft;
        nodeLeftRight->right->left = nodeLeftRightRight;

        // update heights
        nodeLeftRight->left->height = nodeHeight(nodeLeftRight->left);
        node->height = nodeHeight(node);
        nodeLeftRight->height = nodeHeight(nodeLeftRight);

        // return new root after rotation
        return nodeLeftRight;
    }

    Node* RRRotation(Node *node)
    {
        // save nodes addresses
        Node *nodeRight = node->right;
        Node *nodeRightLeft = node->right->left;

        // perform rotation
        nodeRight->left = node;
        node->right = nodeRightLeft;

        // update heights ( using node's height properties not recursively )
        node->height = nodeHeight(node);
        nodeRight->height = nodeHeight(nodeRight);

        // return new root after rotation
        return nodeRight;
    }

    Node* RLRotation(Node *node)
    {
        // save nodes addresses
        Node *nodeRightLeft = node->right->left;
        Node *nodeRightLeftLeft = node->right->left->left;
        Node *nodeRightLeftRight = node->right->left->right;
        
        // perform rotation
        nodeRightLeft->right = node->right;
        nodeRightLeft->left = node;
        nodeRightLeft->left->right = nodeRightLeftLeft;
        nodeRightLeft->right->left = nodeRightLeftRight;
        
        // update heights
        nodeRightLeft->left->height = nodeHeight(nodeRightLeft->left);
        nodeRightLeft->right->height = nodeHeight(nodeRightLeft->right);
        nodeRightLeft->height = nodeHeight(nodeRightLeft);
        
        // return new root after rotation
        return nodeRightLeft;
    }

    /*
        root node height is starting from 1 instead of 0, it just affect
        analysis of tree height not balance factor. if tree have 3 nodes
        and its balance factor is 2 then rotation performs, height don't have 
        role in it e.g in this case height is 3 and if tree have 4 nodes and 
        its balance factor is 1 and height is 3 then no rotation is performed.
    */

    void insert(int data)
    {
        root = insert(root, data);
    }
    Node* insert(Node* node, int data)
    {
        if(node == nullptr)
        {
            node = new Node(data);
            return node;
        }
        else if(data < node->data)
        {
            node->left = insert(node->left,data);
        }
        else if(data > node->data)
        {
            node->right = insert(node->right,data);
        }

        // update height recursively
        node->height = nodeHeight(node);

        // perform rotation if height is unbalanced
        if(balanceFactor(node) == 2 && balanceFactor(node->left) == 1)
        {
            return LLRotation(node);
        }
        else if(balanceFactor(node) == 2 && balanceFactor(node->left) == -1)
        {
            return LRRotation(node);
        }
        else if(balanceFactor(node) == -2 && balanceFactor(node->right) == -1)
        {
            return RRRotation(node);
        }
        else if(balanceFactor(node) == -2 && balanceFactor(node->right) == 1)
        {
            return RLRotation(node);
        }

        return node;
    }

    void showAVL()
    {
        cout<<"AVL Data: ";
        showAVL(root);
        cout<<endl <<"----------------------------------------" <<endl;
    }
    void showAVL(Node *node)
    {
        if(node != nullptr)
        {
            showAVL(node->left);
            cout<<node->data <<"  ";
            showAVL(node->right);
        }
    }

    Node* searchData(int data)
    {
        Node *searchedNode = searchData(root,data);
        return searchedNode;
    }
    Node* searchData(Node *node, int data)
    {
        if(node != nullptr)
        {
            if(data == node->data)
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

    int predecessor(Node *node)
    {
        if(node->right == nullptr)
        {
            return node->data;
        }
        return predecessor(node->right);
    }

    void deleteNode(int data)
    {
        root = deleteNode(root, data);
    }
    Node* deleteNode(Node *node, int data)
    {
        if(node != nullptr)
        {
            if(data == node->data)
            {
                if(node->left == nullptr && node->right == nullptr)
                {
                    delete node;
                    return nullptr;
                }
                else if(node->left != nullptr && node->right == nullptr)
                {
                    Node *temp = node->left;
                    delete node;
                    return temp;
                }
                else if(node->left == nullptr && node->right != nullptr)
                {
                    Node *temp = node->right;
                    delete node;
                    return temp;
                }
                else
                {
                    if(node->left->right == nullptr)
                    {
                        node->left->right = node->right;
                        Node *temp = node->left;
                        delete node;
                        return temp;
                    }
                    else
                    {
                        node->data = predecessor(node->left);
                        node->left = deleteNode(node->left, node->data);
                    }
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

            // update height ( using node's height properties not recursively )
            node->height = nodeHeight(node);

            // perform rotation if height is unbalanced
            if(balanceFactor(node) == 2 && balanceFactor(node->left) == 1)
            {
                return LLRotation(node);
            }
            else if(balanceFactor(node) == 2 && balanceFactor(node->left) == -1)
            {
                return LRRotation(node);
            }
            else if(balanceFactor(node) == -2 && balanceFactor(node->right) == -1)
            {
                return RRRotation(node);
            }
            else if(balanceFactor(node) == -2 && balanceFactor(node->right) == 1)
            {
                return RLRotation(node);
            }
        }
        return node;
    }

    void deleteAVL()
    {
        deleteAVL(root);
        root = nullptr;
    }
    void deleteAVL(Node *node)
    {
        if(node != nullptr)
        {
            deleteAVL(node->left);
            deleteAVL(node->right);
            delete node;
        }
    }

    ~AVL()
    {
        deleteAVL(root);
    }
};

int main()
{
    AVL t1;
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
    t1.showAVL();

    Node *searchedData = t1.searchData(10);
    if(searchedData != nullptr)
    {
        cout<<"Searched Data: " <<searchedData->data <<endl;
    }
    else
    {
        cout<<"Data not found!" <<endl;
    }
    cout<<"----------------------------------------" <<endl;

    cout<<"Count Total Nodes: " <<t1.countTotalNodes() <<endl;

    t1.deleteNode(38);
    t1.deleteNode(55);
    t1.deleteNode(50);
    t1.deleteNode(60);
    t1.showAVL();

    return 0;
}