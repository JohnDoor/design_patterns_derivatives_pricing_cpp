#ifndef DOUBLEDIGITAL_H
#define DOUBLEDIGITAL_H
#include "PayOff2.h"

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){}; // Virtual destructor
private:
    double LowerLevel;
    double UpperLevel;
};
#endif // DOUBLE_DIGITAL_H