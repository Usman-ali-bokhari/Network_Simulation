#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>

using namespace std;

template <class T>

class TreeNode
{
public:

	T value;
	TreeNode<T>* left;
	TreeNode<T>* right;

	TreeNode() {
		left = NULL;
		right = NULL;
	}

};


template <class T>

class SplayTree {

public:

	TreeNode<T>* root;


	SplayTree() {
		root = NULL;
	}


	TreeNode<T>* getRoot() {
		return root;
	}



	void insertNode(T num) {

		TreeNode<T>* newNode;
		TreeNode<T>* nodePtr;

		newNode = new TreeNode<T>;
		newNode->value = num;

		newNode->left = NULL;
		newNode->right = NULL;

		if (root == NULL) {

			root = new TreeNode<T>;
			root->value = num;

		}

		else {

			nodePtr = root;
			while (nodePtr != NULL) {

				if (num < nodePtr->value) { // Left subtree

					if (nodePtr->left) {
						nodePtr = nodePtr->left;
					}
					else {
						nodePtr->left = newNode;
						root = splay(root, num);
						break;
					}
				}

				else if (num > nodePtr->value) { // Right subtree

					if (nodePtr->right) {
						nodePtr = nodePtr->right;
					}

					else {
						nodePtr->right = newNode;
						root = splay(root, num);
						break;
					}
				}

				else {
					cout << "Duplicate value found in tree.\n";
					break;
				}
			}
		}
	}


	void makeDeletion(TreeNode<T>*& nodePtr) {

		TreeNode<T>* tempNodePtr;

		if (nodePtr->right == NULL) {

			tempNodePtr = nodePtr;
			nodePtr = nodePtr->left;
			delete tempNodePtr;

		}

		else if (nodePtr->left == NULL) {

			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNodePtr;

		}

		else {

			tempNodePtr = nodePtr->right;

			while (tempNodePtr->left) {
				tempNodePtr = tempNodePtr->left;
			}

			tempNodePtr->left = nodePtr->left;
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNodePtr;

		}

	}

	void Inorder(TreeNode<T>* root)

	{
		if (!root) {
			return;
		}

		Inorder(root->left);
		cout << root->value << endl;

		Inorder(root->right);
	}

	TreeNode<T>* SingleRotateWithLeft(TreeNode<T>* x) {

		TreeNode<T>* y;
		y = x->left;
		x->left = y->right;
		y->right = x;

		return y;
	}


	TreeNode<T>* SingleRotateWithRight(TreeNode<T>* x)
	{
		TreeNode<T>* y = x->right;
		x->right = y->left;
		y->left = x;

		return y;
	}

	TreeNode<T>* splay(TreeNode<T>* t, T value) {

		if (!t) {
			return t;
		}

		TreeNode<T>* tempTree = new TreeNode<T>;
		TreeNode<T>* rightTreeTemp = nullptr, * leftTreeTemp = nullptr;
		rightTreeTemp = leftTreeTemp = tempTree;


		for (; ; ) {
			if (value < t->value) {
				if (t->left == NULL) {
					break;
				}
				if (value < t->left->value) {
					t = SingleRotateWithLeft(t);
				}
				if (t->left == NULL) {
					break;
				}
				rightTreeTemp->left = t;
				rightTreeTemp = t;
				t = t->left;
			}
			else if (value > t->value) {
				if (t->right == NULL) {
					break;
				}
				if (value > t->right->value) {
					t = SingleRotateWithRight(t);
				}
				if (t->right == NULL) {
					break;
				}
				leftTreeTemp->right = t;
				leftTreeTemp = t;
				t = t->right;
			}
			else {
				break;
			}
		}
		leftTreeTemp->right = t->left;
		rightTreeTemp->left = t->right;
		t->left = tempTree->right;
		t->right = tempTree->left;
		this->root = t;
		return t;
	}

};
