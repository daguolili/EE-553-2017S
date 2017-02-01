//Sum reciprocals
//Author: Guoli Sun ID: 10395608
#include <iostream>
using namespace std;

int main()
{
    float sum1f = 0.0f, sum2f = 0.0f;   //Sum reciprocals as float
    for(float i = 1.0f; i <= 100.0f; i++){
        sum1f += 1/i;
    }
    for(float i = 100.0f; i >= 1.0f; i--){
        sum2f += 1/i;
    }
    cout << "The result as float:" << endl;
    cout << "sum1: " << sum1f <<  "\nsum2: " << sum2f << endl;
    cout << "sum1 - sum2 = " << sum1f - sum2f << endl;
    
    double sum1d = 0.0, sum2d = 0.0;    //Sum reciprocals as double
    for(double i = 1.0; i <= 100.0; i++){
        sum1d += 1/i;
    }
    for(double i = 100.0; i >= 1.0; i--){
        sum2d += 1/i;
    }
    cout << "The result as double:" << endl;
    cout << "sum1: " << sum1d <<  "\nsum2: " << sum2d << endl;
    cout << "sum1 - sum2 = " << sum1d - sum2d << endl;
    return 0;
}
