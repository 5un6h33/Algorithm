#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
    string data;
    TreeNode *left;
    TreeNode *right;
};

class BST
{
public:
    BST();
    ~BST();
    int Length();
    void Insert(string item);
    void Delete(string item);
    void Print();
    bool Find(string item);

private:
    TreeNode *root;
    int CountNode(TreeNode *node);
    void DeleteItem(TreeNode *&node, string item);
    void DeleteNode(TreeNode *&node);
    void GetMaxNode(TreeNode *node, string &data);
    void PreOrder(TreeNode *node);
    void InOrder(TreeNode *node);
    void PostOrder(TreeNode *node);
    void FindItem(TreeNode *node, string item, bool &found);
    void Destroy(TreeNode *node);
};

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    Destroy(root);
}

int BST::Length()
{
    return CountNode(root);
}

int BST::CountNode(TreeNode *node)
{
    if (node == NULL)
        return 0;
    else
        return CountNode(node->left) + CountNode(node->right) + 1;
}

void BST::Insert(string item)
{
    TreeNode *newNode = new TreeNode;
    TreeNode *tempNode = NULL;
    newNode->data = item;

    if (root == NULL)
        root = newNode;
    else
    {
        TreeNode *ptr = root;

        while (ptr != NULL)
        {
            tempNode = ptr;
            if (newNode->data < ptr->data)
                ptr = ptr->left;
            else if (newNode->data > ptr->data)
                ptr = ptr->right;
            else
                return;
        }

        if (newNode->data < tempNode->data)
            tempNode->left = newNode;
        else
            tempNode->right = newNode;
    }
}

void BST::Delete(string item)
{
    DeleteItem(root, item);
}

void BST::DeleteItem(TreeNode *&node, string item)
{
    if (item < node->data)
        DeleteItem(node->left, item);
    else if (item > node->data)
        DeleteItem(node->right, item);
    else
        DeleteNode(node);
}

void BST::DeleteNode(TreeNode *&node)
{
    string data;
    TreeNode *tempNode;

    tempNode = node;
    if (node->left == NULL)
    {
        node = node->right;
        delete tempNode;
    }
    else if (node->right == NULL)
    {
        node = node->left;
        delete tempNode;
    }
    else
    {
        GetMaxNode(node->left, data);
        node->data = data;
        DeleteItem(node->left, data);
    }
}

void BST::GetMaxNode(TreeNode *node, string &data)
{
    while (node->right != NULL)
        node = node->right;
    data = node->data;
}

void BST::PreOrder(TreeNode *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    PreOrder(node->left);
    PreOrder(node->right);
}

void BST::InOrder(TreeNode *node)
{
    if (node == NULL)
        return;

    InOrder(node->left);
    cout << node->data << " ";
    InOrder(node->right);
}

void BST::PostOrder(TreeNode *node)
{
    if (node == NULL)
        return;

    PostOrder(node->left);
    PostOrder(node->right);
    cout << node->data << " ";
}

void BST::Print()
{
    cout << "Preorder : ";
    PreOrder(root);
    cout << endl;
    cout << "Postorder : ";
    PostOrder(root);
    cout << endl;
    cout << "Inorder : ";
    InOrder(root);
    cout << endl;
}

bool BST::Find(string item)
{
    bool found;
    FindItem(root, item, found);
    return found;
}

void BST::FindItem(TreeNode *node, string item, bool &found)
{
    if (node == NULL)
        found = false;
    else if (item < node->data)
        FindItem(node->left, item, found);
    else if (item > node->data)
        FindItem(node->right, item, found);
    else
        found = true;
}

void BST::Destroy(TreeNode *node)
{
    if (node == NULL)
        return;
    Destroy(node->left);
    Destroy(node->right);
    delete node;
}