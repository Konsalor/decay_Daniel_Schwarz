//=============================================================================
//	APPLICATION:	decay
//	MODULE:			main
//	PURPOSE:
//	AUTHOR(S):		das
//
//	5/1/2018 5:34:14 PM	Created.
//=============================================================================
#include <iostream>
#include "valueSet.h"
#include <math.h>
#include <random>
#include <string>
#include <fstream>
using namespace std;
//-----------------------------------------------------------------------------
//	THE MAIN ENTRY POINT TO THE PROGRAM.
//
//	input:	argc	The number of arguments of the programme.
//			argv	The vector of arguments of the programme.
//	return:	The code of the reason the process was terminated for.
//			The value defaults to zero.
//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	int seed;
	const int size	= 10000;
	int		max;
	double A0[size];
	double t[size];
	double um[size];
	double A[size];

	double maxAlpha		= 0;

	double meanA0	= 0;
	double meant	= 0;
	double meanum	= 0;
	double meanA	= 0;

	ofstream ostr("decay_Daniel_Schwarz.rlt", ofstream::out | ofstream::trunc);
	
	ValueSet test [size];


	cout << "Please type in a seed for the programm :";
	cin >> seed;
	cout << endl;

	srand(seed);

	for (int i = 0; i < size; i++) {
		A0[i] = fmod(rand(), (1.65*pow(10, -0.5)- 1.25*pow(10, -0.5))) + 1.25*pow(10, -0.5);
		t[i] = rand() % (295-175) + 175;
		um[i] = fmod(rand(), 5.38 - 1.12) + 1.12;

		test[i] = ValueSet(A0[i], t[i], um[i]);

		A[i] = test[i].calculateAlpha();

		if (A[i] > maxAlpha) {
			maxAlpha = A[i];
			max = i;
		}
		 }

	for (int i = 0; i < size; i++) {
		meanA0 += A0[i];
		meant += t[i];
		meanum += um[i];
		meanA += A[i];
		
	}

	meanA0 /= size;
	meant /= size;
	meanum /= size;
	meanA /= size;

	if (ostr.is_open()) {
		ostr << "Daniel " << "Schwarz " << endl;
		ostr << "C++ Programming Language Course" << endl;
		ostr << "Value of seed: " << seed << endl << endl << endl;
		ostr << "Number of the case: " << max << endl;
		ostr << "Concentration of 1,2 dichlorobenzene: " << maxAlpha << " mol/m3" << endl;
		ostr << "Temperature of this reaction: " << t[max] << "°C" << endl;
		ostr << "Mean linear velocity of gas flow: " << meanum << " m/s" << endl;
		ostr << "Maximum output of concenration of the maximum reaction: " << A[max] << " mol/m3" << endl;
		ostr << "Maximum reaction yield: " << maxAlpha << " %" << endl << endl << endl;


		ostr.close();
	}


	
	cout << meanA0 << endl;
	cout << meant << endl;
	cout << meanum << endl;
	cout << meanA << endl;

	cout << "t:" << t[0] << endl;
	cout << "b:" << test[0].calculateb() << endl;
	cout << "k:" << test[0].calculatek() << endl;
	cout << "alpha:" << test[0].calculateAlpha() << endl;
	cout << "A:" << test[0].calculateA() << endl;
	cout << "T:" << test[0].calculateTempKelv() << endl;

	cout << "Testreseult nr: " << max << endl;
	cout << "maxAlpha:" << maxAlpha << endl;



	return 0;
}
