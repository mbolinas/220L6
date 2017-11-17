/*
 * AVLTree.hpp
 *
 *  Created on: Nov 17, 2017
 *      Author: Marc
 */

#ifndef AVLTree_HPP_
#define AVLTree_HPP_

#include <string>
#include <iostream>
#include "NodeT.hpp"
using namespace std;

class AVLTree{
	friend class Game;
	NodeT *root;
	bool AVLTreeflag;

public:
	AVLTree(bool flag);
	bool findWord(string s, NodeT *n);
	void addNode(string s, NodeT *r);
	void printIO(NodeT *root);
	void printPre(NodeT *root);
	void printPost(NodeT *root);

	void adjustHeights(NodeT *n);
	void updateHeights(NodeT *n);

	NodeT *rotateRight(NodeT *n);
	NodeT *rotateLeft(NodeT *n);
	int getDiff(NodeT *n);
};



#endif /* AVLTree_HPP_ */
