//RobotLocationEstimator
//Author:Guoli Sun ID:10395608
#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

const double pi = 4.0*atan(1.0);

int main()
{
    double a, b, x = 0.0, y =0.0;
    while(1){
        cin >> a;
        cin >> b;
        if(a < 0 || b < 0){     // The requirment to stop program
            cout << "program terminates" << endl;
            exit(0);
        }
        else{   // get the location
            x = x + b * cos((90.0-a)*pi/180.0);
            y = y + b * sin((90.0-a)*pi/180.0);
            cout.precision(5);      // set precision
            cout << "Location: x = "<< x << ", y = " << y << endl;
        }
    }
    return 0;
}

