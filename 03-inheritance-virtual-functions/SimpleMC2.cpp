#include "SimpleMC2.h"
#include "Random1.h"
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif

// now input Payoff object instead of OptionType and Strike
// pass by reference to avoid copying
double SimpleMonteCarlo(const PayOff& thePayOff,
                       double Expiry,
                       double Spot,
                       double Vol,
                       double r,
                       unsigned long NumberOfPaths)
{
    double variance = Vol * Vol * Expiry; // s^2 * t
    double rootVariance = sqrt(variance); // sqrt(s^2 * t)
    double itoCorrection = -0.5 * variance; // -0.5 * s^2 * t

    //S*exp(r*t-0.5*s^2*t)
    double movedSpot = Spot*exp(r*Expiry+itoCorrection);
    double thisSpot;
    double runningSum = 0.0;

    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        //S*exp(r*t-0.5*s^2*t) * exp(sqrt(s^2*t)*Z) = S*exp(r*t-0.5*s^2*t + sqrt(s^2*t)*Z)
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayOff = thePayOff(thisSpot);
        runningSum += thisPayOff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry); // Discount the mean payoff
    return mean;
}
