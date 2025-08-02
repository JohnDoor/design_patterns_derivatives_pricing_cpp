/*
requires: 
    PayOff2.cpp
    SimpleMC2.cpp
    Random1.cpp
*/
#include "SimpleMC2.h"
#include "DoubleDigital.h"
#include <iostream>
using namespace std;

int main()
{
    double Expiry = 1.0; // 1 year
    double LowerLevel = 90.0; // Lower level for double digital
    double UpperLevel = 110.0; // Upper level for double digital
    double Spot = 100.0; // Current stock price
    double Vol = 0.2; // 20% volatility
    double r = 0.05; // 5% risk-free interest rate
    unsigned long NumberOfPaths = 100000; // Number of Monte Carlo paths

    char useDefaults;
    cout << "Use default values? (y/n): ";
    cin >> useDefaults;
    
    if (useDefaults != 'y' && useDefaults != 'Y') {
        cout << "\nEnter Expiry\n";
        cin >> Expiry;
        cout << "\nEnter low barrier\n";
        cin >> LowerLevel;
        cout << "\nEnter up barrier\n";
        cin >> UpperLevel;
        cout << "\nEnter Spot\n";
        cin >> Spot;
        cout << "\nEnter Volatility\n";
        cin >> Vol;
        cout << "\nEnter Risk-free interest rate\n";
        cin >> r;
        cout << "\nEnter Number of Paths\n";
        cin >> NumberOfPaths;
    } else {
        cout << "\nUsing default values.\n";
    }

    PayOffDoubleDigital thePayOff(LowerLevel, UpperLevel);

    double result = SimpleMonteCarlo(thePayOff,
                                    Expiry, 
                                    Spot, 
                                    Vol, 
                                    r, 
                                    NumberOfPaths);
    
    cout << "\n the price is: " << result << endl;

    double tmp;
    cin >> tmp; // Wait for user input before closing
}