#define USE_MATH_DEFINES

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

// Calculate the European vanilla call price based on
// underlying S, strike K, risk−free rate r, volatility of
// underlying sigma and time to maturity T
double call_price (const double& S, const double& K, const double& r,
                   const double& v, const double& T) {
    return S * norm_cdf(d_j(1, S, K, r, v, T))-K*exp(-r*T) *
               norm_cdf(d_j(2, S, K, r, v, T));
}

// Calculate the European vanilla put price based on
// underlying S, strike K, risk−free rate r, volatility of
// underlying sigma and time to maturity T
double put_price (const double& S, const double& K, const double& r,
                   const double& v, const double& T) {
    return -S * norm_cdf(-d_j(1, S, K, r, v, T))+K*exp(-r*T) *
               norm_cdf(-d_j(2, S, K, r, v, T));
}

int main(int argc, char **argv) {
    // First we create the parameter list
    double S = 100.0; // Option price
    double K = 100.0; // Strike price
    double r = 0.05; // Risk−free rate (5%)
    double v = 0.2; // Volatility of the underlying (20%) 
    double T = 1.0; // One year until expiry

    // Then we calculate the call/put price
    double call = call_price(S, K, r, v, T);
    double put = put_price(S, K, r, v, T);

    // Finally we output the parameters and prices
    std::cout << "Underlying: " << S << std::endl;
    std::cout << "Strike: " << K << std::endl;
    std::cout << "Risk-Free Rate: " << r << std::endl;
    std::cout << "Volatility: " << v << std::endl;
    std::cout << "Maturity: " << T << std::endl;

    std::cout << "Call Price: " << call << std::endl;
    std::cout << "Put Price: " << put << std::endl;

    return 0;
}