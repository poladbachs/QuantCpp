#ifndef PDE_CPP
#define PDE_CPP

#include "pde.h"
#include <math.h>

BlackScholesPDE::BlackScholesPDE(VanillaOption* _option) : option(_option) {}

double BlackScholesPDE::diff_coeff (double t , double x) const { 
    double vol = option->sigma ;
    return 0.5*vol*vol*x*x; // \frac{1}{2} \sigmaˆ2 Sˆ2
}

double BlackScholesPDE::conv_coeff(double t, double x) const { 
    return option->r*x; // rS
}

double BlackScholesPDE::zero_coeff(double t, double x) const {
    return -(option->r); // -r
}

double BlackScholesPDE::source_coeff(double t, double x) const {
    return 0.0;
}

// Left boundary condition (vanilla call option)
double BlackScholesPDE::boundary_left(double t, double x) const {
    return 0.0; // Specifically for a CALL option
}

// Right boundary condition (vanilla call option)
double BlackScholesPDE::boundary_right(double t, double x) const {
    // This is via Put-Call Parity and works for a call option
    return (x - (option->K) * exp(-(option->r) * ((option->T) - t)));
}

// Initial condition (vanilla call option)
double BlackScholesPDE::init_cond(double x) const {
    return option->pay_off->operator()(x);
}

#endif