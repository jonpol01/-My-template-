/**************************************************************
	08/19/2016      funcN_pretest.cpp
	Created by John Paul Soliva on 8/20/16.
	Copyright © 2016 Soliva John Paul. All rights reserved.

	𝑓(𝑛)=𝑓(𝑛−1)+ 𝑓(𝑛−2)
***************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

// N finder
struct N_Finder{
	float N(int i_val){
		int i_f_N1, i_f_N2 = 0;
		i_f_N1 = n_def(i_val, 1);		//First argument f(n -1)
		i_f_N2 = n_def(i_val, 2);		//Second argument f(n -2)
		return i_f_N1 + i_f_N2;		//return the value f(n - 1) + f(n-2)
	}
	float n_def(float i_val, int n_minus){

		//n = n - 1
		float i_newval;
		i_newval = i_val - n_minus;
		i_newval = i_newval * 0.5 + 0.5;

		/* value debug */
		//cout << "Value of f(" << val << " - " << n_minus << "): " << newval << endl;

		//round-off the value to produce a whole number
		return lround(i_newval);
	}
};

//alias it to make a function FIND.N meaning FIND N
N_Finder FIND;

int main(int argc, char *argv[]){

	//final value container
	float i_nval = 0;

	//Empty input checker
	if(argc < 2) {
		cout << "error: Missing input!\n";
		cout << "Usage: ./<filename><space><n>";
		cout << "\n-------------------------------------------" << endl << endl;
		return 1;
	}

	//get the output value from our N finder
	//and pass it to i_nval then print
	i_nval = FIND.N(atoi(argv[1]));
	cout << "f(n) = f(n-1) + f(n-2)" << endl;
	cout << "f(" << argv[1] << ") = " << i_nval;
	cout << "\n-------------------------------------------\n" << endl;
	return 0;
}