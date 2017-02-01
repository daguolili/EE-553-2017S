//print string
//Author: Guoli Sun ID:10395608
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char x;
    int new_num = 0;    //reverse the number n
    while(n > 0){
                new_num = new_num*10 + (n % 10);
                n /= 10;
    }
    while(new_num){     //convert numbers to strings
        x = new_num % 10 + '0';
        new_num /= 10;
        cout << x;
    }
    return 0;
}
