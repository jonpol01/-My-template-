/**************************************************************
	08/26/2016      node_pretest.cpp
	Created by John Paul Soliva on 8/20/16.
	Copyright © 2016 Soliva John Paul. All rights reserved.


***************************************************************/
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

const int i_maxDepth = 3;

// Structure of our node
struct node {
	int value;
	node *left;
	node *right;
};

// Prototypes
bool isPrime(int);
void addToTree(node*&, node*);
void listTree(node*, int);

static int i_left, i_right = 1;

int main() {
	// First create our forrest vector to hold our trees
	vector<node*> myforrestvector;

	// Two variables, i is for our loop and r is for our random number
	int i = 0;
	int r = 0;

	// Create three pointers to nodes
	// We set them to NULL so they are not pointing at anything... yet!
	node *eventree = NULL;				//even	-unimplemented
	node *oddtree = NULL;				//odd	-unimplemented
	node *primetree = NULL;				//Prime	-unimplemented
	node *valveTree = NULL;
	// Seed our random number generator
	srand((int)time(NULL));

	while (1) {
		// Get a random number
		r = rand() % 100 + 1;

		//Inherit all value to a node regardless of it is an
		//Even or Odd or Prime number
		node *valveItem = new node();
		valveItem->value = r;
		addToTree(valveTree,valveItem);

		i++;
		if (i_left >= i_maxDepth & i_right >= i_maxDepth) {
			i_left = i_right = 0;
			break;
		}
	}

	// Build our forrest by pushing the tree roots onto our vector
	myforrestvector.push_back(valveTree);
	//myforrestvector.push_back(eventree);				//-unimplemented
	//myforrestvector.push_back(oddtree);				//-unimplemented

	// Create an iterator of type node*
	vector<node*>::iterator iterate;

	// We start a loop using begin to refer to the beginning of the vector and
	// we continue until we hit the end of the vector. Each item in our forrest
	// is a special binary tree.
	for (iterate = myforrestvector.begin(); iterate != myforrestvector.end(); iterate++) {
		cout << "\nlisting random Nodes inorder..." << endl << "---------------------" << endl;
		// Dereference the root and give the pointer to a tree root to printTree
		listTree((*iterate) , 0);
		cout  <<  "-----End of list-----" << endl << endl;
	}

	return 0;
}

// In charage of adding a node item to our specific trees.
void addToTree(node *&tree, node *item) {
	if (tree == NULL) {
		// If no root in the tree, make it the first.
		tree = item;
		if(item->value <= 1) return;
	}
	else {
		// Setup a pointer to our root which we can then keep track
		// of current node as we traverse the tree.
		node *temp = tree;
		bool flag = false;

		while (!flag) {
			// If node value is less than current node, we check the left branch
			// If it is null, we place the new node there. Otherwise we set the
			// current node to the left branch and go back through the loop.
			if (item->value < temp->value && i_left <= 3) {
				if (temp->left == NULL) { temp->left = item; flag = true; ++i_left; }
				else { temp = temp->left; }
			}
			else if (item->value > temp->value && i_right <= 3) {
				if (temp->right == NULL) { temp->right = item; flag = true; ++i_right; }
				else { temp = temp->right; }
			}
			else {
				// The node value was the same as an current node, so dump it.
				flag = true;
			}
		}
	}
}

// Print out a given tree using recursion
void listTree(node *aNode, int i_dir) {

	// Recurse down left node till we hit bottom leaf
	if (aNode->left != NULL) {
		listTree(aNode->left, 1);
	}

	// Print the value of the node we are at and every time we move
	// back up
	cout << aNode->value;
	if (i_dir == 1) cout << "\t --left node";
	else if(i_dir == 2)cout << "\t --right node";
	else cout << "\t --ROOT";
	cout << endl;

	// Traverse down the right branch now recursively
	if (aNode->right != NULL) {
		listTree(aNode->right, 2);
	}
}