#include <iostream>
#include <cmath>
#include <queue>
#include "RadixTreeType.h"

#define	MAXBITS	64

using namespace std;

RadixTreeType::RadixTreeType()
{
	root = NULL;
}

RadixTreeType::~RadixTreeType()	
{
	// Memory deletion needed
}

void	RadixTreeType::print()  // Use of breadth-first search
{
	if(root == NULL) return;
	queue<Node*>	q;
	q.push(root);
	while(!q.empty()) {
		int iCount = q.size();
		for(int i = 0;i < iCount;i++) {
			Node *t = q.front();
			cout << t->info << ' ';
			q.pop();
			if(t->left != NULL) q.push(t->left);
			if(t->right != NULL) q.push(t->right);
		}
		cout << endl;
	}
}

int	nthbit(int item, int nth)
{
	int mask = pow(2, nth);
	if((item & mask) == 0) return 0;
	return 1;
}

bool	RadixTreeType::RetrieveItem(int item)
{
	Node *t = root;

	for(int i = 0;i < MAXBITS;i++) { 
		if(t == NULL) return false;
		if(t->info == item) return true;
		int b = nthbit(item, i);
		// Implement here...
		

	}
	return false;
}

void	RadixTreeType::InsertItem(int item)
{
	if(root == NULL) {
		root = new Node;
		root->info = item;
		root->left = root->right = NULL;
		return;
	}
	Node	*t = root;
	for(int i = 0;i < MAXBITS;i++) { 
		int b = nthbit(item, i);
		if(b == 1) { 	// Implement here for a right child...




		} else {	// Implement here for a left child...




		}
	}
}

void	findLeaf(Node *tree, Node* &leaf, Node* &leaf_parent)
{
	leaf_parent = tree;
	leaf = tree;
	while(leaf->left != NULL || leaf->right != NULL) {
		leaf_parent = leaf;
		if (leaf->left != NULL)
			leaf = leaf->left;
		else
			leaf = leaf->right;
	}
}

void	RadixTreeType::DeleteItem(int item)
{
	// Search first...
	Node *t, *parent;
       	t = root;
	parent = NULL;
	bool found = false;
	for(int i = 0;i < MAXBITS;i++) {
		if(t == NULL) return;
		if(t->info == item) {
			found = true;
			break;
		}
		int b = nthbit(item, i);
		if(b == 1) {
			parent = t;
			t = t->right;
		} else {
			parent = t;
			t = t->left;	
		}
	}
	if(found == false) return;
	// Now delete actually
	Node *leaf, *leaf_parent;
	findLeaf(t, leaf, leaf_parent);
	// If leaf == leaf_parent, then t is a leaf node.
	// Implement here for a node deletion...





}
