//Mystery Sum
//Author:Guoli Sun ID:10395608
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float s1 = 0.0f;
    for(float i=1.0f; i <= 10000000; i++){
        float sum0 = s1;
        s1 += 1 / (i * i);
        if(s1 == sum0 ){   //find the iteration times
            cout << "we need " << i << " iterations before the contribution of 1/n2 is too small and no longer matters" << endl;
            cout << sqrt(6 * s1) << '\n';
            float s2;
            s2 = s1 + 1 / ((i+1) *(i+1));
            cout << sqrt(6 * s2) << '\n';
            break;
        }
    }
    return 0;
}
