// PayOff.cpp
#include "PayOff.h"
#include <algorithm>    // for std::max
#include <stdexcept>    // for std::invalid_argument

PayOff::PayOff(OptionType TheOptionType_, double Strike_)
    : TheOptionType(TheOptionType_), Strike(Strike_) {}

double PayOff::operator()(double spot) const
{
    switch (TheOptionType)
    {
        case call:
            return std::max(spot - Strike, 0.0);
        case put:
            return std::max(Strike - spot, 0.0);
        default:
            throw std::invalid_argument("Unknown option type");
    }
}
