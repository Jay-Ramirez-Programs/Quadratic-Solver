/*
 *	Author:			Jay Ramirez
 *	Title:			Quadratic Equation Solver
 *	Class:			CSCE-121 530
 *	Last updated:		September 12, 2018
 */

#include <iostream>
#include <cmath>
using namespace std;

int main () {
	//Initialize double variables for storing equation coefficients
	double coeffA;
	double coeffB;
	double coeffC;
	//Initialize boolean variables for storing coefficient sign
	char signA;
	char signB;
	char signC;
	//Initialize double variable for storing discriminant
	double discriminant;

	//Get user input for equation Ax^2+Bx+C=0
	cin >> coeffA >> coeffB >> coeffC;
	
	//Store coefficient signs
	signA = (coeffA >= 0) ? '+' : '-';
	signB = (coeffB >= 0) ? '+' : '-';
	signC = (coeffC >= 0) ? '+' : '-';

	//Calculate discriminant
	discriminant = pow(coeffB, 2.0) - 4 * coeffA * coeffC;

	//In case A = 0
	if ((coeffA < 0.0001) && (coeffA > -0.0001)){
		//In case B = 0 also, output error message
		if ((coeffB < 0.0001) && (coeffB > -0.0001)){
			cout << "0x^2 + 0x " << signC << " " << fabs(coeffC) << " = 0" << endl;
			cout << "Unable to determine root(s)." << endl;
		}
		//In case A = 0 but B is non-zero
		else {
			//Move constant C to other side of equation
			coeffC = -coeffC;
			//Divide negated constant C by B
			double linearSolution = coeffC / coeffB;
			
			cout << "0x^2 " << signB << " " << fabs(coeffB) << "x " << signC << " " << fabs(coeffC) << " = 0" << endl;
			cout << "x = " << linearSolution << endl;
		}
	}
	else {//If A is not zero, we calculate roots based on discriminant
		//When discriminant = 0 there is a single solution
		if ((discriminant < 0.0001) && (discriminant > -0.0001)){
			double singleSolution = (-1) * (coeffB / (2 * coeffA));
			cout << coeffA << "x^2 " << signB << " " << fabs(coeffB) << "x " << signC << " " << fabs(coeffC) << " = 0" << endl;
			cout << "x = " << singleSolution << endl;	
		}
		//When discriminant is positive, we get two real solutions
		else if (discriminant > 0) {
			double halfOneSolution = (-1) * (coeffB / (2 * coeffA));
			double halfTwoSolution = sqrt(discriminant) / (2 * coeffA);
			//Solution obtained by subtraction is first
			double firstSolution = halfOneSolution - halfTwoSolution;
			double secondSolution = halfOneSolution + halfTwoSolution;

			cout << coeffA << "x^2 " << signB << " " << fabs(coeffB) << "x " << signC << " " << fabs(coeffC) << " = 0" << endl;
			cout << "x = " << firstSolution << endl;
			cout << "x = " << secondSolution << endl;
		}
		//When discriminant is negative, we get two complex solutions
		else if (discriminant < 0) {
			double realPart = (-1) * (coeffB / (2 * coeffA));
			//Imaginary part is computed by taking absolute value of discriminant, taking square root as normal
			double imaginaryPart = sqrt(fabs(discriminant)) / (2 * coeffA);
			//Since subtracted solution is first, if the imaginary part is positive, then first solution has a 
			//negative imaginary part
			char signFirstSolution = (imaginaryPart > 0) ? '-' : '+';
			char signSecondSolution = (imaginaryPart > 0) ? '+' : '-';
			
			cout << coeffA << "x^2 " << signB << " " << fabs(coeffB) << "x " << signC << " " << fabs(coeffC) << " = 0" << endl;
			cout << "x = " << realPart << " " << signFirstSolution << " " << fabs(imaginaryPart) << 'i' << endl;
			cout << "x = " << realPart << " " << signSecondSolution << " " << fabs(imaginaryPart) << 'i' << endl;
		}
	}

	return 0;
}
