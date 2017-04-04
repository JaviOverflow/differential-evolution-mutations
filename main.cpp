/*
  CEC13 Test function suite 
  Jane Jing Liang (email: liangjing@zzu.edu.cn) 
  Dec. 23th 2012
*/

#include <iostream>
#include <iomanip>
#include "DE.h"


void test_func(double *, double *,int,int,int);

const vector<int> FUNCTIONS_TO_SOLVE = vector<int>(
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28});

double calculateMean(const double *bestFitness);
double calculateStandardDeviation(const double *bestFitness, double mean);

double *OShift,*M,*y,*z,*x_bound;
int ini_flag=0,n_flag,func_flag;


int main()
{
	double bestFitness[TIMES_PER_FUNCTION];
	double mean, standard_deviation;

	cout << setprecision(16);
	srand((unsigned) time(NULL));

	for (const auto &functionNumber : FUNCTIONS_TO_SOLVE) {

		cout << endl << "-------------------------------------------------------" << endl;
		cout << "Function = " << functionNumber << ", Dimension size = " << DIMENSION << "\n" << endl;

		double optimum = (functionNumber < 15) ?
				  -1500 + functionNumber * 100 : (functionNumber - 14) * 100;

		for (int _ = 0; _ < TIMES_PER_FUNCTION; ++_) {
			DE de = DE();
			bestFitness[_] = de.run(functionNumber, optimum);
			cout << _ + 1 << "th run, " << "best fitness = " << bestFitness[_] << endl;
		}

		mean = calculateMean(bestFitness);
		standard_deviation = calculateStandardDeviation(bestFitness, mean);

		cout << endl << "mean = " << mean << ", std = " << standard_deviation << endl;
	}

	return 0;
}


double calculateMean(const double *bestFitness) {
    double mean = 0;

	for (int i = 0; i < TIMES_PER_FUNCTION; ++i)
			mean += bestFitness[i];
	mean /= TIMES_PER_FUNCTION;

	return mean;
}


double calculateStandardDeviation(const double *bestFitness, double mean) {
	double standard_deviation = 0;

	for (int i = 0; i < TIMES_PER_FUNCTION; ++i)
		standard_deviation += pow(mean - bestFitness[i], 2.0);
	standard_deviation /= TIMES_PER_FUNCTION;
	standard_deviation = sqrt(standard_deviation);

	return standard_deviation;
}
