//sum the numbers from 1 to 100
// Author: Guoli Sun ID: 10395608
#include <iostream>
using namespace std;

int main()
{
    int n = 100;
    int prod1,prod2;
    // using the Gauss formula n(n+1)/2
    prod1 = n*(n+1)/2;
    cout << "Gauss formula: "<< prod1 << endl;
    // using a loop
    for(int i=1; i <= 100; i++){
        prod2 += i;
    }
    cout << "loop: "<< prod2 << endl;
    if(prod1 == prod2){
        cout << "both answers are the same";
    }
    else{
        cout << "both answers are different";
    }
    return 0;
}
