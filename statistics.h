//
// Created by Ionic on 3/4/17.
//

#ifndef CEC13CCODE_2_STATISTICS_H
#define CEC13CCODE_2_STATISTICS_H


#include <cstdlib>
#include <cmath>

//Return random value with uniform distribution [0, 1)
inline double rand_double() { return (double) rand() / (double) RAND_MAX; }


/*
  Return random value from Cauchy distribution with mean "mu" and variance "gamma"
  http://www.sat.t.u-tokyo.ac.jp/~omi/random_variables_generation.html#Cauchy
*/
inline double rand_cauchy(double mu, double gamma) { return mu + gamma * tan(M_PI * (rand_double() - 0.5)); }

/*
  Return random value from normal distribution with mean "mu" and variance "gamma"
  http://www.sat.t.u-tokyo.ac.jp/~omi/random_variables_generation.html#Gauss
*/
inline double rand_gauss(double mu, double sigma) { return mu + sigma * sqrt(-2.0 * log(rand_double())) * sin(2.0 * M_PI *
                                                                                                                     rand_double()); }

#endif //CEC13CCODE_2_STATISTICS_H
