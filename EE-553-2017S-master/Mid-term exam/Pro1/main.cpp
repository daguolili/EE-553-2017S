//Author:Guoli Sun  ID: 10395608
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    cout << "Please input a positive number: ";
    cin >> n;

    //compute the sum
    for(int i = 1; i < n; i++){
        if(n%i == 0){
            sum += i;
        }
    }
    //compare sum with n
    if(n == sum){
        cout << "true" << '\n';
    }else{
        cout << "false" << '\n';
    }
    return 1;
}
