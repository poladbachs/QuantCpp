#ifndef MAIN_NR_CPP
#define MAIN_NR_CPP

#include "black_scholes.h"
#include "newton_raphson.h"
#include <iostream>

#include <iostream>

int main(int argc , char **argv) {
    // First we create the parameter list
    double S = 100.0; // Underlying spot price
    double K = 100.0; // Strike price
    double r = 0.05; // Risk−free rate (5%)
    double T = 1.0; // One year until expiry
    double C_M = 10.5; // Option market price

    // Create black scholes call functor
    BlackScholesCall bsc(S, K, r, T);

    // Newton Raphson parameters
    double init = 0.3; // Our guess impl. vol of 30% 
    double epsilon = 0.001;

    // Calculate implied volatility
    double sigma = newton_raphson<BlackScholesCall, 
                                  &BlackScholesCall::option_price,
                                  &BlackScholesCall::option_vega>
        (C_M, init, epsilon, bsc);

    // Output the values
    std::cout << "Implied Volatility: " << sigma << std::endl;

    return 0;
}

#endif