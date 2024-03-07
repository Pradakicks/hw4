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

bool helper(Node *node, int currDepth, int &currLeafDepth){
    if(node == nullptr) return true;
    if (node->left == nullptr && node->right == nullptr){
        if(currLeafDepth == -1){
            currLeafDepth = currDepth;
            return true;
        } else {
            if(currDepth != currLeafDepth){
                return false;
            }
            return true;
        }
    }

    return helper(node->left, currDepth + 1, currLeafDepth) && helper(node->right, currDepth + 1, currLeafDepth);
		
}

bool equalPaths(Node * root)
{
    // Add your code below
    if (root == nullptr)
		return true;

    int currLeafDepth = -1;
	return helper(root->left, 0, currLeafDepth)  && helper(root->right, 0, currLeafDepth);
}


