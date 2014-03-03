/*
	This program demonstrates a function which 
	approximates sine to ~15 decimal places
	using its Maclaurin series.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <math.h>
#include <time.h>

using namespace std;

const double PI = atan(1.0)*4;
const double TWOPI = PI * 2.0;

double factorial(int n);
double wrapAngle(double angle);
double sin(double theta, double& error);

int main()
{
	double theta, error;
	int degree = 169;
	string input;

	while (true)
	{
		cout << "sin(x),  x = ";
		cin >> theta;

		// start time
		time_t start = clock();

		double _sin = sin(theta, error);

		// time elapsed
		double timeElapsed = (clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

		cout << endl << setprecision(numeric_limits<double>::digits10) << _sin << ", |error| <= " << abs(error)
			<< ", " << timeElapsed * 1000.0 << " ms" << endl << endl;
	}
}

double factorial(int n)
{
	// if n is 0, return 1
	if (!n)
		return 1;

	double result = 1;

	for (int i = 2; i <= n; i++)
		result *= i;

	return result;
}

double wrapAngle(double angle)
{
	if (angle < 0)
		angle = -angle + PI;

	return fmod(angle, TWOPI);
}

double sin(double theta, double& error)
{
	theta = wrapAngle(theta);

	double sin = 0;
	int n;

	for (n = 0; (2*n + 1) <= 169; n++)
	{
		sin += (pow(-1.0, n) * pow(theta, 2*n + 1)) / factorial(2*n + 1);
	}

	error = (pow(-1.0, n + 1) * pow(theta, 2*(n + 1) + 1)) / factorial(2*(n + 1) + 1);

	return sin;
}