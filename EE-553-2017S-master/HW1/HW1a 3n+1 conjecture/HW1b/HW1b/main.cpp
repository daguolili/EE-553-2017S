//Convergence of n-gons
//Author:Guoli Sun ID:10395608
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n = 1000000;
    double r = 1.0;
    cout << "the radius for n=1 is 0" << endl;  // n=1 is the special case
    for(int i = 3; i <= n; i++){    // from i=3 it's reasonable
        r /= cos( M_PI/ i);
        if(i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000){  //choose the data what we want
            cout << "the radius for n=" << i << " is " << r << endl;
        }
    }
    return 0;
}
