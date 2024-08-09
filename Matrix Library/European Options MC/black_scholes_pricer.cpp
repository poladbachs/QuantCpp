#define USE MATH DEFINES

#include <iostream> 
#include <cmath>

// Standard normal probability density function
double norm_pdf(const double& x) {
    return (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x);
}

// An approximation to the cumulative distribution function 
// for the standard normal distribution
// Note: This is a recursive function
double norm_cdf(const double& x) {
    double k = 1.0/(1.0 + 0.2316419*x);
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 +
                   k*(-1.821255978 + 1.330274429*k)))) ;

    if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    } else {
        return 1.0 - norm_cdf(-x) ;
    }
}

// This calculates d j , for j in {1 ,2}. This term appears in the closed 
// form solution for the European call or put price
double d_j(const int& j, const double& S, const double& K, const double& r,
           const double& v, const double& T) {
            return (log(S/K) + (r + (pow(-1,j-1))*0.5*v*v)*T)/(v*(pow(T,0.5))); 
}