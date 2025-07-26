// main.cpp
#include "Random.h"
#include <iostream>
#include <cmath>

using namespace std;

double SimpleMonteCarlo1(double Expiry,
    double Strike,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths)
{
    double variance = Vol * Vol * Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;
    double movedSpot = Spot * exp(r * Expiry + itoCorrection);
    double runningSum = 0.0;

    for (unsigned long i = 0; i < NumberOfPaths; ++i)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        double thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = thisSpot - Strike;
        thisPayoff = (thisPayoff > 0) ? thisPayoff : 0;
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry);
    return mean;
}

int main()
{
    double Expiry, Strike, Spot, Vol, r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry: ";
    cin >> Expiry;
    cout << "\nEnter strike: ";
    cin >> Strike;
    cout << "\nEnter spot: ";
    cin >> Spot;
    cout << "\nEnter vol: ";
    cin >> Vol;
    cout << "\nEnter r: ";
    cin >> r;
    cout << "\nNumber of paths: ";
    cin >> NumberOfPaths;

    double result = SimpleMonteCarlo1(Expiry, Strike, Spot, Vol, r, NumberOfPaths);
    cout << "\nThe option price is: " << result << "\n";

    return 0;
}
