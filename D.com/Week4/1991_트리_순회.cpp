#include<iostream>

using namespace std;

// initalize node
typedef char ElementType;
typedef struct tagSBTNode 
{
    struct tagSBTNode * left;
    struct tagSBTNode * right;
    ElementType data;
}SBTNode;

// create node
// SBTNode* SBT_createNode(ElementType data)
// {
//     SBTNode* node = (SBTNode*)malloc(sizeof(SBTNode));
//     node->left = NULL;
//     node->right = NULL;
//     node->data = data;

//     return node;
// }

// // destroy node
// void SBT_destroyNode(SBTNode* node)
// {
//     free(node);
// }

// preorder
void SBT_preorderPrintTree(SBTNode* node)
{
    if(node == NULL)
        return;
    cout << node->data;
    SBT_preorderPrintTree(node->left);
    SBT_preorderPrintTree(node->right);
}

// inorder
void SBT_inorderPrintTree(SBTNode* node)
{
    if(node == NULL)
        return;
    SBT_inorderPrintTree(node->left);
    cout << node->data;
    SBT_inorderPrintTree(node->right);
}

// postorder
void SBT_postorderPrintTree(SBTNode* node)
{
    if(node == NULL)
        return;
    SBT_postorderPrintTree(node->left);
    SBT_postorderPrintTree(node->right);
    cout << node->data;
}

// void SBT_destroyTree(SBTNode* root)
// {
//     if(root == NULL)
//         return;
//     SBT_destroyTree(root->left);
//     SBT_destroyTree(root->right);
//     SBT_destroyTree(root);
// }

int main(void)
{
    std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, nmb;
    cin >> n;

    char chr, nl, nr;

    SBTNode* nodes = (SBTNode*)malloc(sizeof(SBTNode) * n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> chr >> nl >> nr;
        nmb = chr - 'A';
        nodes[nmb].data = chr;

        if(nl == '.')
        {
            nodes[nmb].left = NULL;
        }
        else
        {
            nodes[nmb].left = &nodes[nl - 'A'];
        }

        if(nr == '.')
        {
            nodes[nmb].right = NULL;
        }
        else
        {
            nodes[nmb].right = &nodes[nr - 'A'];
        }
    }

    SBT_preorderPrintTree(&nodes[0]);
    cout << '\n';
    SBT_inorderPrintTree(&nodes[0]);
    cout << '\n';
    SBT_postorderPrintTree(&nodes[0]);

    free(nodes);

    return 0;
}