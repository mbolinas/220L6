/*
 * LL.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: Marc
 */

#include "LL.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


LL::LL(){
	first = NULL;
	last = NULL;
	size = 0;
	score = 0;
}
void LL::addFirst(string s){
	NodeL *n = new NodeL(s);
	first = n;
	last = n;
	size++;
}
void LL::push(string s){
	if(first == NULL){
		addFirst(s);
	}
	else{
		NodeL *n = new NodeL(s);
		last->next = n;
		last = n;
		size++;
	}
}
void LL::printList(){
	NodeL *temp = first;
	while(temp != NULL){
		cout << temp->word << ": " << temp->wscore << ",  ";
		temp = temp->next;
	}
	cout << endl;
}
void LL::getScore(){
	int count = 0;
	NodeL *temp = first;
	while(temp != NULL){
		count += temp->wscore;
		temp = temp->next;
	}
	score = count;
}
