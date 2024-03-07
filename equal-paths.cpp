#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <algorithm>

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int getHeight(Node *node) {
	if (node == nullptr)
		return 0;

	return 1 + max(getHeight(node->left), getHeight(node->right));
}

bool equalPaths(Node * root)
{
    // Add your code below
    if (root == nullptr)
		return true;

	if (getHeight(root->left) - getHeight(root->right) != 0) return false;

	return true;

}

