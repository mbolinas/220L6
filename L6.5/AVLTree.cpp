/*
 * AVLTree.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: Marc
 */

#include "AVLTree.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

AVLTree::AVLTree(bool flag){
	root = NULL;
	AVLTreeflag = flag;
}

bool AVLTree::findWord(string s, NodeT *n){
	NodeT *temp = root;
	while(temp != NULL){
		if(temp->word == s){
			return true;
		}
		else{
			if(s < temp->word){
				temp = temp->left;
			}
			else{
				temp = temp->right;
			}
		}
	}
	return false;
}

void AVLTree::addNode(string s, NodeT *r){
	NodeT *x = new NodeT(s);
	NodeT *temp = root;
	bool flag = false;
	while(!flag){
		if(s < temp->word){
			if(temp->left == NULL){
				temp->left = x;
				x->parent = temp;
				flag = true;
			}
			temp = temp->left;
		}
		else if(s > temp->word){
			if(temp->right == NULL){
				temp->right = x;
				x->parent = temp;
				flag = true;
			}
			temp = temp->right;
		}
		else{
			//if the node already exists in the tree don't do anything
			flag = true;
		}
	}
	if(AVLTreeflag){
		adjustHeights(x);
	}
}

void AVLTree::printIO(NodeT *root){
	if(root != NULL){
		printIO(root->left);
		cout << root->word << ", ";
		printIO(root->right);
	}
}

void AVLTree::printPre(NodeT *root){
	if(root != NULL){
		cout << root->word << ", ";
		printIO(root->left);
		printIO(root->right);
	}
}

void AVLTree::printPost(NodeT *root){
	if(root != NULL){
		printIO(root->left);
		printIO(root->right);
		cout << root->word << ", ";
	}
}

void AVLTree::adjustHeights(NodeT *n){
	NodeT *x = n;
	updateHeights(n);

	x = x->parent;
	while(x != NULL){
		int diff = getDiff(x);

		if(diff > 1 && n->word < x->left->word){
			x = rotateRight(x);
		}
		if(diff < -1 && n->word > x->right->word){
			x = rotateLeft(x);
		}
		if(diff > 1 && n->word > x->left->word){
			x->left = rotateLeft(x->left);
			x = rotateRight(x);
		}
		if(diff < -1 && n->word < x->right->word){
			x->right = rotateRight(x->right);
			x = rotateLeft(x);
		}
		x = x->parent;
	}

}

void AVLTree::updateHeights(NodeT *n){
	while(n != NULL){
		n->height = 1 + max(n->left->height, n->right->height);
		n = n->parent;
	}
}

NodeT *AVLTree::rotateLeft(NodeT *n){
	NodeT *x = n->right;
	NodeT *temp = x->left;
	x->left = n;
	n->right = temp;
	x->parent = n->parent;
	n->parent = x;
	updateHeights(n);

	return x;

}

NodeT *AVLTree::rotateRight(NodeT *n){
	NodeT *x = n->left;
	NodeT *temp = x->right;
	x->right = n;
	n->left = temp;
	x->parent = n->parent;
	n->parent = x;
	updateHeights(n);

	return x;
}

int AVLTree::getDiff(NodeT *n){
	if(n->left == NULL){
		return n->right->height;
	}
	else if(n->right == NULL){
		return n->left->height;
	}
	else if(n->right == NULL && n->left == NULL){
		return 0;
	}
	return n->left->height - n->right->height;
}
