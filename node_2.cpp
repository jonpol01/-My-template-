#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

// Structure of our node
struct node {
	int value;
	node *left;
	node *right;
};

// Prototypes
bool isPrime(int);
void addToTree(node*&, node*);
void printTree(node*);

static int i_left, i_right = 0;

int main() {
	// First create our forrest vector to hold our trees
	vector<node*> myforrestvector;

	// Two variables, i is for our loop and r is for our random number
	int i = 0;
	int r = 0;

	// Create three pointers to nodes
	// We set them to NULL so they are not pointing at anything... yet!
	node *eventree = NULL;
	node *oddtree = NULL;
	node *primetree = NULL;
    node *valveTree = NULL;
	// Seed our random number generator
	srand((int)time(NULL));

	while (i < 8) {
		// Get a random number
		r = rand() % 100 + 1;

        //Inherit all value to a node
        //regardless of it is an
        //Even or Odd or Prime number
		node *valveItem = new node();
		valveItem->value = r;
        //cout << valveItem->value << ", " << endl;
		addToTree(valveTree,valveItem);
        
		// Put it in even or odd trees
		if ((r % 2) == 0) { 
			// Even
			node *anEvenItem = new node();
			anEvenItem->value = r;
			///addToTree(eventree,anEvenItem);
		}
		else { 
			// Odd
			node *anOddItem = new node();
			anOddItem->value = r;
			//addToTree(oddtree, anOddItem); 
		}

		// Place it in the prime tree
		if (isPrime(r)) { 
			node *aPrimeItem = new node();
			aPrimeItem->value = r;
			//addToTree(primetree,aPrimeItem); 
		}
		
		i++;
	}

	// Build our forrest by pushing the tree roots onto our vector
	myforrestvector.push_back(valveTree);
//	myforrestvector.push_back(eventree);
//	myforrestvector.push_back(oddtree);
//	myforrestvector.push_back(primetree);

	// Create an iterator of type node*
	vector<node*>::iterator iterate;

	// We start a loop using begin to refer to the beginning of the vector and
	// we continue until we hit the end of the vector. Each item in our forrest
	// is a special binary tree.
	for (iterate = myforrestvector.begin(); iterate != myforrestvector.end(); iterate++) {
		cout << "Printing tree..." << endl;
		// Dereference the root and give the pointer to a tree root to printTree
		printTree((*iterate));
		cout << "End of tree" << endl << endl;
	}

	return 0;
}

// Simple function to determine if the number is prime
// That is, only divisible by 1 and itself.
bool isPrime(int number) {
	if (number > 1) { 
		for (int i = 2; i < number; i++) {
			if ((number % i) == 0) { return false; }
		}
		return true;
	}
	else { return false; }
}

// In charage of adding a node item to our specific trees.
void addToTree(node *&tree, node *item) {
	if (tree == NULL) {
		// If no root in the tree, make it the first.
		tree = item;
        cout << "root: " << item->value << "\n" << endl;
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
//			if (item->value < temp->value && i_left > 2) {
			if (item->value < temp->value) {
				if (temp->left == NULL) { temp->left = item; flag = true; i_left++; }
				else { temp = temp->left; i_left++; }
                cout << "left: " << i_left << endl;
			}
//			else if (item->value > temp->value && i_right > 2) {
			else if (item->value > temp->value) {
				if (temp->right == NULL) { temp->right = item; flag = true; i_right++; }
				else { temp = temp->right; i_right++; }
                cout << "right: " << i_right << endl;
			}
			else {
				// The node value was the same as an current node, so dump it.
				flag = true;
			}
            if (i_left >= 2 || i_right >= 2){
                i_left = 0;
                i_right = 0;
            }
		}
	}
}

// Print out a given tree using recursion
void printTree(node *aNode) {
	
	// Recurse down left node till we hit bottom leaf
	if (aNode->left != NULL) {
		printTree(aNode->left);
	}

	// Print the value of the node we are at and every time we move
	// back up

	cout << aNode->value << endl;

	// Traverse down the right branch now recursively
	if (aNode->right != NULL) {
		printTree(aNode->right);
	}
}