/*Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BSt or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. Assume unique elements will be given.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
wherer, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
Note : main function is given for your reference which we are using internally to test the class.*/

/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
class BST {
	BinaryTreeNode<int>* root;

	public:

	BST() {
		root = NULL;
	}

	~BST() {
		delete root;
	}

	private:
	BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node) {
		if (node == NULL) {
			return NULL;
		}

		if (data > node->data) {
			node->right = deleteData(data, node->right);
			return node;
		} else if (data < node->data) {
			node->left = deleteData(data, node->left);
			return node;
		} else {
			if (node->left == NULL && node->right == NULL) {
				delete node;
				return NULL;
			} else if (node->left == NULL) {
				BinaryTreeNode<int>* temp = node->right;
				node->right = NULL;
				delete node;
				return temp;
			} else if (node->right == NULL) {
				BinaryTreeNode<int>* temp = node->left;
				node->left = NULL;
				delete node;
				return temp; 
			} else {
				BinaryTreeNode<int>* minNode = node->right;
				while (minNode->left != NULL) {
					minNode = minNode->left;
				}
				int rightMin = minNode->data;
				node->data = rightMin;
				node->right = deleteData(rightMin, node->right);
				return node;
			}
		}
	}

	void printTree(BinaryTreeNode<int>* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data << ":";
		if (root->left != NULL && root->right != NULL) {
			cout << "L:" << root->left->data<< ",R:" << root->right->data;
		}

		else if (root->left == NULL && root->right != NULL) {
			cout << "R:" << root->right->data;
		}
        else if( root->left != NULL && root->right == NULL){
            cout << "L:" << root->left->data<<",";
        }
		cout << endl;
		printTree(root->left);
		printTree(root->right);
	}


	public:
	void remove(int data) {
		root = deleteData(data, root);	
	}

	void print() {
		printTree(root);
	}

	private:
	BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node) {
		if (node == NULL) {
			BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
			return newNode;
		}

		if (data <= node->data) {
			node->left = insert(data, node->left);
		} else {
			node->right = insert(data, node->right);
		}
		return node;
	}

	public:
	void insert(int data) {
		this->root = insert(data, this->root);
	}

	private:
    
	bool hasData(int data, BinaryTreeNode<int>* node) {
		if (node == NULL) {
			return false;
		}

		if (node->data == data) {
			return true;
		} else if (data < node->data) {
			return hasData(data, node->left);
		} else {
			return hasData(data, node->right);
		}
	}

	public:
	bool search(int data) {
		return hasData(data, root);
	}
};

#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

#include "solution.h"

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}

