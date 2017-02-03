//Windchill
//Author:Guoli Sun ID:10395608
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double T, V, windchill;
    cout << "Calm ";
    for(T = 40; T >= -45; T -=5){
        cout << T << ' ';
    }
    cout << endl;
    for(V = 5; V <= 60; V += 5){    // nested loops
        cout << V << ' ';
        for(T = 40; T >= -45; T -= 5){
            windchill = 35.74 + 0.6215 * T - 35.75 * pow(V, 0.16) + 0.4275 * T * pow(V, 0.16);
            cout << round(windchill) << ' ';    // use round() to accomplish rounding
        }
        cout << endl;
    }
    return 0;
}
