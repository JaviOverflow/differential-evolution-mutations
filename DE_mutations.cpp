//
// Created by Ionic on 4/4/17.
//

#include "DE.h"
#include "statistics.h"


void DE::mutate_DE_rand_1(int individual) {
    const double F = rand_double() * 2;

    int a = rand() % POPULATION_SIZE;
    int b = rand() % POPULATION_SIZE; while (b == a) b = rand() % POPULATION_SIZE;
    int c = rand() % POPULATION_SIZE; while (c == a && c == b) c = rand() % POPULATION_SIZE;

    Individual A = population[a];
    Individual B = population[b];
    Individual C = population[c];

    trial[individual] = A + F * (B - C);
}

void DE::mutate_DE_best_1(int individual) {
    const double F = rand_double() * 2;

    int a = rand() % POPULATION_SIZE;
    int b = rand() % POPULATION_SIZE; while (b == a) b = rand() % POPULATION_SIZE;

    Individual A = population[a];
    Individual B = population[b];

    trial[individual] = bestIndividual + F * (A - B);
}

void DE::mutate_DE_ctr_1(int individual) {
    const double F1 = rand_double() * 2;
    const double F2 = rand_double() * 2;

    int a = rand() % POPULATION_SIZE;
    int b = rand() % POPULATION_SIZE; while (b == a) b = rand() % POPULATION_SIZE;
    int c = rand() % POPULATION_SIZE; while (c == a && c == b) c = rand() % POPULATION_SIZE;

    Individual A = population[a];
    Individual B = population[b];
    Individual C = population[c];
    Individual current = population[individual];

    trial[individual] = current + F1 * (A - current) + F2 * (B - C);
}

void DE::mutate_DE_ctb_1(int individual) {
    const double F1 = rand_double() * 2;
    const double F2 = rand_double() * 2;

    int a = rand() % POPULATION_SIZE;
    int b = rand() % POPULATION_SIZE; while (b == a) b = rand() % POPULATION_SIZE;

    Individual A = population[a];
    Individual B = population[b];
    Individual current = population[individual];

    trial[individual] = current + F1 * (bestIndividual - current) + F2 * (A - B);
}

void DE::mutate_DE_ctpb_1(int individual) {
    const double F1 = rand_double() * 2;
    const double F2 = rand_double() * 2;
    const int    p  = rand() % POPULATION_SIZE;

    int a = rand() % POPULATION_SIZE;
    int b = rand() % POPULATION_SIZE; while (b == a) b = rand() % POPULATION_SIZE;

    Individual A = population[a];
    Individual B = population[b];
    Individual current = population[individual];

    sort(population.begin(), population.end());
    Individual pBestIndividual = population[rand() % (p + 1)];

    trial[individual] = current + F1 * (pBestIndividual - current) + F2 * (A - B);
}
