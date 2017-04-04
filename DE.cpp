//
// Created by Ionic on 3/4/17.
//

#include <iostream>
#include <iomanip>
#include "DE.h"
#include "statistics.h"


double DE::run(const int functionNumber, double optimum) {

    currentEvaluationsAmount = 0;

    initializePopulations();
    evaluateFitness(population, functionNumber);
    updateBestIndividual();

    while (false == isOptimumIndividualFound(optimum) && currentEvaluationsAmount < MAX_EVALUATIONS_AMOUNT) {
        mutate();
        crossover();
        evaluateFitness(trial, functionNumber);
        selection_();
        updateBestIndividual();
    }

    return bestIndividual.fitness - optimum;
}

bool DE::isOptimumIndividualFound(double optimum) {
    if ((bestIndividual.fitness - optimum) > EPSILON)
        return false;

    bestIndividual.fitness = optimum;
    return true;
}

void DE::initializePopulations() {
    population = vector<Individual>(POPULATION_SIZE, {vector<double>(DIMENSION), -1});
    for (auto &individual : population)
        for (auto &chromosome : individual.value)
            chromosome = LOWER_BOUND + (UPPER_BOUND - LOWER_BOUND) * rand_double();
    trial = vector<Individual>(POPULATION_SIZE, {vector<double>(DIMENSION), -1});
}

void DE::evaluateFitness(vector<Individual> &population, const int functionNumber) {
    for (auto &individual : population)
        test_func(&individual.value[0], &individual.fitness, DIMENSION, 1, functionNumber);
    currentEvaluationsAmount += POPULATION_SIZE;
}

void DE::updateBestIndividual() {
    bestIndividual = *min_element(population.begin(), population.end());
}

void DE::mutate() {
    for (int individual = 0; individual < POPULATION_SIZE; ++individual) {
        mutate_DE_ctpb_1(individual);
    }

}

void DE::crossover() {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        int rndC = rand() % DIMENSION;

        for (int j = 0; j < DIMENSION; ++j) {
            double rndS = rand_double();

            if (rndS > CR && rndC != j)
                trial[i].value[j] = population[i].value[j];
        }
    }
}

void DE::selection_() {
    for (int i = 0; i < POPULATION_SIZE; ++i)
        if (population[i] > trial[i])
            population[i] = trial[i];
}

