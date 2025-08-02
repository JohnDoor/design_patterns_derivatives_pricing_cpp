#include "PayOff2.h"
#include <algorithm>    // for std::max
#include <stdexcept>    // for std::invalid_argument

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
    if (Strike_ < 0) {
        throw std::invalid_argument("Strike price cannot be negative");
    }
}
double PayOffCall::operator()(double Spot) const
{
    return std::max(Spot - Strike, 0.0);
}
PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
    if (Strike_ < 0) {
        throw std::invalid_argument("Strike price cannot be negative");
    }
}
double PayOffPut::operator()(double Spot) const
{
    return std::max(Strike - Spot, 0.0);
}