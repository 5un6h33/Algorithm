// 트리 순회
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

// 별찍기-10
#include<iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int count = n / 3;
            while(count != 0)
            {
                if((i / count) % 3 == 1 && (j / count) % 3 == 1)
                {
                    cout << " ";
                    break;
                }
                count /= 3;
            }
            if(count == 0)
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}

// 이진수 변환
#include<iostream>

using namespace std;

void binary(unsigned long long n)
{
    if(n != 1) binary(n / 2);
    cout << (n % 2);
}

int main(void)
{
    long long n;
    cin >> n;
    binary(n);
    cout << endl;

    return 0;
}

// 에너지 모으기
#include<iostream>
#include<vector>

using namespace std;

int max_num = 0, temp = 0;
vector<int> v;

void e_max()
{
    if(v.size() == 2)
    {
        if(max_num < temp)
            max_num = temp;
        return;
    }

    for(int i = 1; i < v.size() - 1; i++)
    {
        int select = v[i];
        temp = temp + v[i - 1] * v[i + 1];
        v.erase(v.begin() + i);
        e_max();
        v.insert(v.begin() + i, select);
        temp = temp - v[i - 1] * v[i + 1];
    }
}

int main(void)
{
    int n, num;
    cin >> n;
    
    while(n--)
    {
        cin >> num;
        v.push_back(num);
    }
    e_max();
    cout << max_num;

    return 0;
}

//하노이 탑 이동 순서
#include<iostream>

using namespace std;

void HanoiTower(int n, int from, int via, int to)
{
    if(n == 1)
    {
        printf("%d %d\n", from, to);
    }
    else {
        HanoiTower(n - 1, from, to, via);
        printf("%d %d\n", from, to);
        HanoiTower(n - 1, via, from, to);
    }
}

int main(void)
{
    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    HanoiTower(n, 1, 2, 3);

    return 0;
}

