#include "stdafx.h"
#include "iostream"
#include "CourseWork.h"
#include "string"
#include "sstream"
using namespace std;

Tree::Tree()
{
	root = nullptr;
	count = 0;
}

Tree::~Tree()
{
	delete root;
}

void Tree::insert(int key, Node* leaf)
{
	if (key < leaf->data) {
		if (leaf->left != nullptr) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new Node;
			leaf->left->data = key;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else if (key >= leaf->data) {
		if (leaf->right != nullptr) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new Node;
			leaf->right->data = key;
			leaf->right->right = nullptr;
			leaf->right->left = nullptr;
		}
	}
}

void Tree::insert(int key)
{
	count++;
	if (root != nullptr) {
		insert(key, root);
	}
	else {
		root = new Node;
		root->data = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}

string Tree::inorder()
{
	string str;
	return inorder(root, str);
}

string Tree::inorder(Node* leaf, string str)
{
	if (leaf != nullptr) {
		str = inorder(leaf->left, str);
		str.append(to_string(leaf->data));
		str.append(" ");
		str = inorder(leaf->right, str);
	}
	return str;
}

string Tree::unique()
{
	string str = inorder();
	string unique;
	int *arr = new int[count];
	int repeat;
	istringstream ss(str); 

	for (int i = 0; i < count; ++i) {
		ss >> arr[i];
	}
	for (int i = 0; i < count; ++i) {
		repeat = 0;
		for (int j = 0; j < count; j++) {
			if (arr[i] == arr[j]) {
				repeat++;
			}
		}
		if (repeat == 1) {
			unique.append(to_string(arr[i]));
			unique.append(" ");
		}
	}
	return unique;
}

string Tree::maxTimes()
{
	string str = inorder();
	string maxTimes;
	int *arr = new int[count];
	int repeat, max = 0;
	istringstream ss(str);

	for (int i = 0; i < count; ++i) {
		ss >> arr[i];
	}
	for (int i = 0; i < count; ++i) {
		repeat = 0;
		for (int j = 0; j < count; j++) {
			if (arr[i] == arr[j]) {
				repeat++;
			}
		}
		if (repeat > max) {
			max = repeat;
		}
	}
	for (int i = 0; i < count; ++i) {
		repeat = 0;
		for (int j = 0; j < count; j++) {
			if (arr[i] == arr[j]) {
				repeat++;
			}
		}
		if ((repeat == max) && (arr[i] != arr[i - 1])) {
			maxTimes.append(to_string(arr[i]));
			maxTimes.append(" ");
		}
	}
	return maxTimes;
}
