/*
 * LL.hpp
 *
 *  Created on: Nov 17, 2017
 *      Author: Marc
 */

#ifndef LL_HPP_
#define LL_HPP_


#include <string>
#include <iostream>
#include "NodeL.hpp"
using namespace std;

class LL{

public:
	NodeL *first;
	NodeL *last;
	int size;
	int score;
	LL();
	void push(string s);
	void addFirst(string s);
	void printList();
	void getScore();
};

#endif /* LL_HPP_ */
