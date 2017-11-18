/*
 * mainWordHub.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: Debra
 */


//#include "AVLTree.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Game.hpp"

using namespace std;

int main() {

	srand(time(NULL));

	cout << "RUNNING WITH AVLFLAG = FALSE" << endl;
	Game *avlfalse = new Game("testdict.txt", false);

	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "*****************************************************************************" << endl;
	cout << endl << endl;

	cout << "RUNNING WITH AVLFLAG = TRUE" << endl;
	Game *avltrue = new Game("testdict.txt", true);



	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "*****************************************************************************" << endl;
	cout << endl << endl;

	cout << "RUNNING GAME WITH FULL SCRABBLE DICTIONARY (avlflag = true)" << endl;
	Game *game = new Game("scrabble.txt", true);
	game->startGame();

	return 0;
}

