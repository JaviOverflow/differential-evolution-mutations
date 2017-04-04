//
// Created by Ionic on 3/4/17.
//

#include "Individual.h"

Individual::Individual(const vector<double> &value, double fitness) : value(value), fitness(fitness) {}

bool Individual::operator<(const Individual &rhs) const {
    return this->fitness < rhs.fitness;
}

bool Individual::operator>(const Individual &rhs) const {
    return this->fitness > rhs.fitness;
}

Individual operator+(const Individual &lhs, const Individual &rhs) {
    Individual result = Individual({vector<double>(lhs.value.size()), -1});

    for (int i = 0; i < lhs.value.size(); ++i)
        result.value[i] = lhs.value[i] + rhs.value[i];

    return result;
}

Individual operator-(const Individual &lhs, const Individual &rhs) {
    Individual result = Individual({vector<double>(lhs.value.size()), -1});

    for (int i = 0; i < lhs.value.size(); ++i)
        result.value[i] = lhs.value[i] - rhs.value[i];

    return result;
}


Individual operator*(const Individual &lhs, const double rhs) {
    Individual result = Individual({vector<double>(lhs.value.size()), -1});

    for (int i = 0; i < lhs.value.size(); ++i)
        result.value[i] = lhs.value[i] * rhs;

    return result;
};

Individual operator*(const double lhs, const Individual &rhs) {
    return rhs * lhs;
};

