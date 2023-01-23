#include <bits/stdc++.h>
template <typename T>
class BinaryTreeNode
{

public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data);
    ~BinaryTreeNode();
};
template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T data)
{
    this->data = data;
    left = NULL;
    right = NULL;
}

template <typename T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
    delete left;
    delete right;
}
using namespace std;

BinaryTreeNode<int> *taktInputLevelorder()
{
    // cout << "enter root data" << endl;
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        // cout << "enter left child of " << front->data << " : ";
        int data;
        cin >> data;
        if (data != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(data);
            front->left = leftNode;
            pendingNodes.push(leftNode);
        }
        // cout << "enter right child of " << front->data << " : ";
        cin >> data;
        if (data != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(data);
            front->right = rightNode;
            pendingNodes.push(rightNode);
        }
    }

    return root;
}
void inOrder(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
BinaryTreeNode<int> *leafDelete(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }

    root->left = leafDelete(root->left);
    root->right = leafDelete(root->right);

    return root;
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelorder(root);
    cout << "Inorder traversal of the given tree" << endl;
    inOrder(root);
    cout << endl;
    cout << "Inorder traversal of the tree after deletion of leaf nodes" << endl;
    root = leafDelete(root);
    inOrder(root);

    return 0;
}
