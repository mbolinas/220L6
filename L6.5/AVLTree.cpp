/*
 *
 *	Marc Bolinas
 *	Brian Phillips
 *
 *	11/19/17
 *
 *
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
	if(root == NULL){
		root = x;
		flag = true;
	}
	while(!flag){
		if(s < temp->word){
			if(temp->left == NULL){
				//cout << "Inserting left of " << temp->word << endl;
				temp->left = x;
				x->parent = temp;
				flag = true;
			}
			temp = temp->left;
		}
		else if(s > temp->word){
			if(temp->right == NULL){
				//cout << "Inserting right of " << temp->word << endl;
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

	if(root == NULL){
		return;
	}
	else{
		printIO(root->left);
		cout << root->word << endl;
		printIO(root->right);
	}
}

void AVLTree::printPre(NodeT *root){
	if(root == NULL){
		return;
	}
	else{
		cout << root->word << endl;
		printPre(root->left);
		printPre(root->right);
	}
}

void AVLTree::printPost(NodeT *root){
	if(root == NULL){
		return;
	}
	else{
		printPost(root->left);
		printPost(root->right);
		cout << root->word << endl;
	}
}

void AVLTree::adjustHeights(NodeT *n){
	NodeT *x = n;
	updateHeights(n);

	x = x->parent;
	while(x != NULL){
		//cout << "rotation root: " << x->word << endl;
		int diff = getDiff(x);
		//cout << "difference: " << diff << endl;

		if(diff > 1 && n->word < x->left->word){
			//cout << "ll" << endl;
			x = rotateRight(x);
			if(x->parent == NULL){
				root = x;
			}
		}
		if(diff < -1 && n->word > x->right->word){
			//cout << "rr" << endl;
			x = rotateLeft(x);
			if(x->parent == NULL){
				root = x;
			}
		}
		if(diff > 1 && n->word > x->left->word){
			//cout << "lr" << endl;
			rotateLeft(x->left);
			x = rotateRight(x);
			if(x->parent == NULL){
				root = x;
			}
		}
		if(diff < -1 && n->word < x->right->word){
			//cout << "rl" << endl;
			rotateRight(x->right);
			x = rotateLeft(x);
			if(x->parent == NULL){
				root = x;
			}
		}
		x = x->parent;
	}

}

void AVLTree::updateHeights(NodeT *n){
	while(n != NULL){
		if(n->left == NULL && n->right == NULL){
			n->height = 0;
		}
		else if(n->left == NULL){
			n->height = 1 + n->right->height;
		}
		else if(n->right == NULL){
			n->height = 1 + n->left->height;
		}
		else{
			n->height = 1 + max(n->left->height, n->right->height);
		}
		n = n->parent;
	}
}

NodeT *AVLTree::rotateLeft(NodeT *n){
	NodeT *x = n->right;
	NodeT *temp = x->left;
	x->left = n;
	n->right = temp;
	x->parent = n->parent;
	if(n->parent != NULL && n->parent->left != NULL && n->word == n->parent->left->word){
		x->parent->left = x;
	}
	if(n->parent != NULL && n->parent->right != NULL && n->word == n->parent->right->word){
		x->parent->right = x;
	}
	n->parent = x;
	if(temp != NULL){
		temp->parent = n;
	}
	updateHeights(n);

	return x;

}

NodeT *AVLTree::rotateRight(NodeT *n){
	NodeT *x = n->left;
	NodeT *temp = x->right;
	x->right = n;
	n->left = temp;
	x->parent = n->parent;
	if(n->parent != NULL && n->parent->left != NULL && n->word == n->parent->left->word){
		x->parent->left = x;
	}
	if(n->parent != NULL && n->parent->right != NULL && n->word == n->parent->right->word){
		x->parent->right = x;
	}
	n->parent = x;
	if(temp != NULL){
		temp->parent = n;
	}
	updateHeights(n);

	return x;
}

int AVLTree::getDiff(NodeT *n){
	if(n->left == NULL){
		return (n->right->height - (2 * n->right->height)) - 1;
	}
	else if(n->right == NULL){
		return n->left->height + 1;
	}
	else if(n->right == NULL && n->left == NULL){
		return 0;
	}
	else{
		return n->left->height - n->right->height;
	}
}
