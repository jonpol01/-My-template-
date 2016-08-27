/**************************************************************
	08/20/2016      dice_pretest.cpp
	Created by John Paul Soliva on 8/20/16.
	Copyright © 2016 Soliva John Paul. All rights reserved.


***************************************************************/
#include <iostream>

using namespace std;

//Max faces of our dice
#define DICE_FACES	6

unsigned long long ul_Combi = 0;
short int i_cntArray[1024];		//Combination array container

//Board game combination counter
void boardgameCounter(int i_Tiles , short int i_cntArray[] , int i_len , int i_minValue ){
	//Initiate a combination completion check
	if(i_Tiles <= 0){
		//debugger
		//for( int j = 0 ; j < len ; j++ )    cout << a[ j ] << "," ;
		//cout << endl;

		//Count each succesfull combination
		//Each successful combination we increase by 1
		ul_Combi++;

		return;
	}

	//Combination finder
	for(int i = i_minValue ; i <= i_Tiles ; i++){
		//fill our combination container
		//and break if our loop reach our dice max number faces
		i_cntArray[i_len] = i;
		boardgameCounter(i_Tiles - i , i_cntArray , i_len + 1 , i );//permutation
		if(i >= DICE_FACES) break;
	}
}

int main(int argc, char *argv[]){
	//Empty input checker
	if(argc < 2) {
		cout << "error: Missing input!\n";
		cout << "Usage: ./<filename><space><number of steps>";
		cout << "\n-------------------------------------------" << endl << endl;
		return 1;
	}

	//User input of a board game steps
	short int i_boardTiles = (atoi(argv[1]));

	//initiate combinations counter
	boardgameCounter(i_boardTiles, i_cntArray, 0, 1);
	cout << "Number of spaces: " << i_boardTiles << endl;
	cout << "combinations: " << ul_Combi << " counts" ;
	//print an End with a total number of steps acquired
	cout << "\n-------------------------------------------\n" << endl;
	return 0;
}