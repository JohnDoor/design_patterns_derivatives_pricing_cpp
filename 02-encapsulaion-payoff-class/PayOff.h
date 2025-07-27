// PayOff.h
#ifndef PAYOFF_H
#define PAYOFF_H

// Regular C-style enum (not enum class)
enum  OptionType { call, put };

class PayOff
{
public:
    //enum OptionType { call, put };
    PayOff(OptionType TheOptionType_, double Strike_);
    double operator()(double spot) const;

private:
    OptionType TheOptionType;
    double Strike;
};

#endif // PAYOFF_H

