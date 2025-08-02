#include "SimpleMC2.h"
#include <iostream>
using namespace std;

int main()
{
    double Expiry = 1.0; // 1 year
    double Strike = 100.0; // Strike price
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
        cout << "\nEnter Strike\n";
        cin >> Strike;
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

    PayOffCall callPayoff( Strike);
    PayOffPut putPayoff( Strike);

    double resultCall = SimpleMonteCarlo(callPayoff,
                                    Expiry, 
                                    Spot, 
                                    Vol, 
                                    r, 
                                    NumberOfPaths);
    double resultPut = SimpleMonteCarlo(putPayoff,
                                    Expiry, 
                                    Spot, 
                                    Vol, 
                                    r, 
                                    NumberOfPaths);
    cout << "Call Option Price: " << resultCall << endl;
    cout << "Put Option Price: " << resultPut << endl;

    double tmp;
    cin >> tmp; // Wait for user input before closing
    return 0;
}