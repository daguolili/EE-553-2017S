//Author: GUOLI SUN
//ID: 10395608

#include <iostream>
#include <cmath>
using namespace std;

double cal(double n, double x){
    double result = 0;
    int temp = 1;
    for(int i = 1; i <= n; i++)
    {
        temp = 1;
        for(int j = i; j >= 1; j--)
        {
            temp *= j;
        }
        result += temp / pow(x, n);
    }
    cout << result << '\n';
    return result;
}

int main()
{
    double n, x;
    cout << "Press the number n and x: " <<'\n';
    cin >> n;
    cin >> x;
    if(n <= 0 || x == 0){
        cout << "n should be larger than 0 and x should not be equal to 0!" <<'\n';
        exit(0);
    }
    cout << "The result is " << cal(n, x);
    return 0;
}
