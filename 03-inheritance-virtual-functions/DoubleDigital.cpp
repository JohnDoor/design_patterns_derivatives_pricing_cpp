#include "DoubleDigital.h"
#include <stdexcept>    // for std::invalid_argument

PayOffDoubleDigital::PayOffDoubleDigital(double LowerLevel_,
                                            double UpperLevel_)
                        : LowerLevel(LowerLevel_), 
                        UpperLevel(UpperLevel_)
{
    if (LowerLevel_ >= UpperLevel_) {
        throw std::invalid_argument("Lower level must be less than upper level");
    }
}

double PayOffDoubleDigital::operator()(double Spot) const
{
    if (Spot < LowerLevel) {
        return 0.0; // Below the lower level, payoff is zero
    }
    if (Spot > UpperLevel) { 
        return 0.0; // Above the upper level, payoff is zero
    }
    // If Spot is between LowerLevel and UpperLevel
    return 1.0; // Inside the range, payoff is one
}