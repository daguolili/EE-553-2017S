//Read in number and compute n factorial
//Author: Guoli Sun ID:10395608
#include <iostream>
using namespace std;

int main()
{
    int n, prob = 1;
    cin >> n;
    for(int i=n; i >=1; i--){   // loop for getting factorial
        prob *= i;
    }
    cout << "n=" << n << " " << prob << endl;
    return 0;
}
