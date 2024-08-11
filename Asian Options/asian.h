#ifndef ASIAN_H 
#define ASIAN_H

#include <vector> 
#include "pay_off.h"

class AsianOption {
protected:
    PayOff* pay_off; // Pay−off class (in this instance call or put)

public:
    AsianOption(PayOff* pay_off );
    virtual  ~AsianOption () {};

    // Pure virtual pay−off operator (this will determine arithmetic or geometric )
    virtual double pay_off_price(const std::vector<double>& spot_prices) 
        const = 0;
};

class AsianOptionArithmetic : public AsianOption {
public:
    AsianOptionArithmetic(PayOff* pay_off );
    virtual  ~AsianOptionArithmetic () {};

    // Override the pure virtual function to produce arithmetic Asian Options
    virtual double pay_off_price(const std::vector<double>& spot_prices) 
        const;
};

class AsianOptionGeometric : public AsianOption {
public:
    AsianOptionGeometric(PayOff* pay_off );
    virtual  ~AsianOptionGeometric () {};

    // Override the pure virtual function to produce arithmetic Asian Options
    virtual double pay_off_price(const std::vector<double>& spot_prices) 
        const;
};

#endif