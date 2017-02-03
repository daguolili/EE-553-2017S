//Functions
//Author:Guoli Sun ID:10395608
#include <iostream>
using namespace std;

//compute n factorial using a loop
unsigned long long fact(unsigned long long n){
    unsigned long long prod = 1;
    for(unsigned long long i = 1; i <= n; i++){
        prod *= i;
    }
    return prod;
}

//compute n factorial using recursion
unsigned long long fact2(unsigned long long n){
    if(n == 1){
        return 1;
    }
    else{
        return n * fact2(n-1);
    }
}

//compute fibonacci number using a loop
unsigned long long fibo(unsigned long long n){
    unsigned long long num = 1, num2 = 1, fibonacci;
    if(n == 1){
        return num;
    }
    if(n == 2){
        return num2;
    }
    for(unsigned long long i = 3; i <= n ; i++){
        fibonacci = num + num2;
        num = num2;
        num2 = fibonacci;
    }
    return fibonacci;
}

//compute fibonacci number using recursion
unsigned long long fibo2(unsigned long long n){
    unsigned long long num;
    if(n == 1){
        return 1;
    }
    else if (n == 2) {
        return 1;
    }
    else{
        num = fibo2(n - 2) + fibo2(n - 1);
    }
    return num;
}

//choose the number of ways to play the NY lottery
unsigned long long choose(unsigned long long n, unsigned long long r){
    unsigned long long C[100][100];
    if(r > n){
        return 0;
    }
    if(r == n || r == 0){
        return 1;
    }
    if(C[n][r] != 0){
        return C[n][r];
    }
    return C[n][r] = choose(n-1, r-1) + choose(n-1,r) ;
}

int main()
{
    cout << fact(5) << ' ' << fact2(5) << '\n';
    cout << fact(15) << ' ' << fact2(15) << '\n';
    cout << fibo(5) << ' ' << fibo2(5) << '\n';
    cout << fibo(13) << ' ' << fibo2(13) << '\n';
    cout << choose(52,6) << '\n';
    return 0;
}
