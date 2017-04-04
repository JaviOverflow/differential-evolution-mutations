//
// Created by Ionic on 3/4/17.
//

#ifndef CEC13CCODE_2_DE_H
#define CEC13CCODE_2_DE_H

#include <stdlib.h>
#include <vector>
#include <cmath>
#include "Individual.h"

using namespace std;

void test_func(double *, double *, int, int, int);

const double EPSILON = pow(10.0, -8);
const int TIMES_PER_FUNCTION = 10;
const int DIMENSION = 10;
const int POPULATION_SIZE = 100;
const int MAX_EVALUATIONS_AMOUNT = DIMENSION * 10000;

const double CR = 0.8;

const double UPPER_BOUND = 100;
const double LOWER_BOUND = -100;


class DE {
public:
    double run(const int functionNumber, double optimum);

private:

    int currentEvaluationsAmount;
    vector<Individual> population;
    vector<Individual> trial;
    Individual bestIndividual;

    void initializePopulations();

    void evaluateFitness(vector<Individual> &population, const int functionNumber);

    void updateBestIndividual();

    bool isOptimumIndividualFound(double optimum);

    void mutate();

    void crossover();

    void selection_();

    void mutate_DE_rand_1(int individual);

    void mutate_DE_best_1(int individual);

    void mutate_DE_ctr_1(int individual);

    void mutate_DE_ctb_1(int individual);

    void mutate_DE_ctpb_1(int individual);

};


#endif //CEC13CCODE_2_DE_H
