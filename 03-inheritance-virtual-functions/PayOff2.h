#ifndef PAYOFF2_H
#define PAYOFF2_H

class PayOff
{
    public:
        PayOff(){};
        virtual double operator()(double Spot) const = 0; // Pure virtual function
        virtual ~PayOff(){}; // Virtual destructor
    private:
};
class PayOffCall : public PayOff
{
    public:
        PayOffCall(double Strike_);
        virtual double operator()(double Spot) const;
        virtual ~PayOffCall(){}; // Virtual destructor
    private:
        double Strike;
};
class PayOffPut : public PayOff
{
    public:
        PayOffPut(double Strike_);
        virtual double operator()(double Spot) const;
        virtual ~PayOffPut(){}; // Virtual destructor
    private:
        double Strike;
};
#endif // PAYOFF2_H