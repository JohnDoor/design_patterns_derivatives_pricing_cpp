#include <iostream>
#include "PayOff.h"

int main()
{
    double strike = 100.0;
    double spot = 105.0;

    // Use classic enum values directly: call / put
    PayOff callPayoff(call, strike);
    PayOff putPayoff(put, strike);

    std::cout << "Call Payoff: " << callPayoff(spot) << std::endl;
    std::cout << "Put Payoff: " << putPayoff(spot) << std::endl;


    return 0;
}

