#include "BST.hpp"

// 3D CUBE
class Node
{
public:
    BST *tree;
    Node *right;
    Node *left;
    Node *up;
    Node *down;
    Node *front;
    Node *back;
};

class Cube
{
private:
    Node node000, node001, node002;
    Node node100, node101, node102;
    Node node200, node201, node202;

    Node node010, node011, node012;
    Node node110, node111, node112;
    Node node210, node211, node212;

    Node node020, node021, node022;
    Node node120, node121, node122;
    Node node220, node221, node222;

public:
    Cube()
    {
        node000.tree = new BST;
        node001.tree = new BST;
        node002.tree = new BST;
        node100.tree = new BST;
        node101.tree = new BST;
        node102.tree = new BST;
        node200.tree = new BST;
        node201.tree = new BST;
        node202.tree = new BST;

        node010.tree = new BST;
        node011.tree = new BST;
        node012.tree = new BST;
        node110.tree = new BST;
        node111.tree = new BST;
        node112.tree = new BST;
        node210.tree = new BST;
        node211.tree = new BST;
        node212.tree = new BST;

        node020.tree = new BST;
        node021.tree = new BST;
        node022.tree = new BST;
        node120.tree = new BST;
        node121.tree = new BST;
        node122.tree = new BST;
        node220.tree = new BST;
        node221.tree = new BST;
        node222.tree = new BST;

        node000.back = &node010;
        node010.back = &node020;
        node020.front = &node010;
        node010.front = &node000;

        node100.back = &node110;
        node110.back = &node120;
        node120.front = &node110;
        node110.front = &node100;

        node200.back = &node210;
        node210.back = &node220;
        node220.front = &node210;
        node210.front = &node200; //왼쪽 윗라인 앞뒤 연결

        node001.back = &node011;
        node011.back = &node021;
        node021.front = &node011;
        node011.front = &node001;

        node101.back = &node111;
        node111.back = &node121;
        node121.front = &node111;
        node111.front = &node101;

        node201.back = &node211;
        node211.back = &node221;
        node221.front = &node211;
        node211.front = &node201; //가운데 라인 앞뒤 연결

        node002.back = &node012;
        node012.back = &node022;
        node022.front = &node012;
        node012.front = &node002;

        node102.back = &node112;
        node112.back = &node122;
        node122.front = &node112;
        node112.front = &node102;

        node202.back = &node212;
        node212.back = &node222;
        node222.front = &node212;
        node212.front = &node202; //오른쪽 라인 앞뒤 연결

        node000.down = &node100;
        node100.down = &node200;
        node200.up = &node100;
        node100.up = &node000;

        node001.down = &node101;
        node101.down = &node201;
        node201.up = &node101;
        node101.up = &node000;

        node002.down = &node102;
        node102.down = &node202;
        node202.up = &node102;
        node102.up = &node002;

        node000.right = &node001;
        node001.right = &node002;
        node002.left = &node001;
        node001.left = &node000;

        node100.right = &node101;
        node101.right = &node102;
        node102.left = &node101;
        node101.left = &node100;

        node200.right = &node201;
        node201.right = &node202;
        node202.left = &node201;
        node201.left = &node200; //맨 앞면 세팅 (2차원 linked list)

        node010.down = &node110;
        node110.down = &node210;
        node210.up = &node110;
        node110.up = &node010;

        node011.down = &node111;
        node111.down = &node211;
        node211.up = &node111;
        node111.up = &node010;

        node012.down = &node112;
        node112.down = &node212;
        node212.up = &node112;
        node112.up = &node012;

        node010.right = &node011;
        node011.right = &node012;
        node012.left = &node011;
        node011.left = &node010;

        node110.right = &node111;
        node111.right = &node112;
        node112.left = &node111;
        node111.left = &node110;

        node210.right = &node211;
        node211.right = &node212;
        node212.left = &node211;
        node211.left = &node210; //중간면 큐브 세팅

        node020.down = &node120;
        node120.down = &node220;
        node220.up = &node120;
        node120.up = &node020;

        node021.down = &node121;
        node121.down = &node221;
        node221.up = &node121;
        node121.up = &node020;

        node022.down = &node122;
        node122.down = &node222;
        node222.up = &node122;
        node122.up = &node022;

        node020.right = &node021;
        node021.right = &node022;
        node022.left = &node021;
        node021.left = &node020;

        node120.right = &node121;
        node121.right = &node122;
        node122.left = &node121;
        node121.left = &node120;

        node220.right = &node221;
        node221.right = &node222;
        node222.left = &node221;
        node221.left = &node220; //맨 뒷면 큐브 세팅

        //여기까지 3차원 큐브 만드는 과정
    }

    // 좌표에 위치한 큐브 찾기
    Node *GetNode(int z, int y, int x)
    {
        Node *tempNode;
        tempNode = &node000;
        for (int i = 0; i < x; i++)
            tempNode = tempNode->right;
        for (int i = 0; i < y; i++)
            tempNode = tempNode->back;
        for (int i = 0; i < z; i++)
            tempNode = tempNode->down;

        return tempNode;
    }

    void Insert(int z, int y, int x, string item)
    {
        Node *Block = GetNode(z, y, x);
        Block->tree->Insert(item);
    }

    void Delete(int z, int y, int x, string item)
    {
        Node *Block = GetNode(z, y, x);
        Block->tree->Delete(item);
    }

    void Find(string item)
    {
        Node *tempNode;
        for (int z = 0; z < 3; z++)
        {
            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    tempNode = GetNode(z, y, x);
                    if (tempNode->tree->Find(item))
                        cout << z << y << x << endl;
                }
            }
        }
    }

    void Print(int z, int y, int x)
    {
        Node *Block = GetNode(z, y, x);
        Block->tree->Print();
    }

    void Print_All()
    {
        Node *tempNode;
        for (int z = 0; z < 3; z++)
        {
            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    tempNode = GetNode(z, y, x);
                    cout << tempNode->tree->Length() << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
};