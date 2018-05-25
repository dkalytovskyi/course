#include "stdafx.h"
#include "string"
#include "vector"
using namespace std;
#ifndef binary_tree_included
#define binary_tree_included
class Tree {
private:
	struct Node {
		int data;
		Node *left;
		Node *right;
	};
	Node *root;
	int count;
	void insert(int key, Node *leaf);
	string inorder(Node *leaf, string str);
public:
	Tree();
	~Tree();
	string unique();
	string maxTimes();
	void insert(int key);
	string inorder();
};
#endif //binary_tree_included

