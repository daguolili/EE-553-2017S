//Primes
//Author: Guoli Sun ID:10395608
#include <iostream>
#include <cmath>
using namespace std;

//function for testing prime or not prime
bool isPrime(unsigned long long p){
    if(p == 2)
        return true;
    if(p % 2 == 0)
        return false;
    for(unsigned long long i = 3;i <= sqrt(p); i += 2 ){
        if(p % i ==0 )
            return false;
        else
            return true;
    }
}

int main(){
    unsigned long long n;
    cout << "Please enter in a number:";
    cin >> n;
    if(isPrime(n)){
            cout << "Number " << n << " is prime number.\n";
    }else{
        cout << "Number " << n << " is not prime number.\n";
    }
    return 0;
}
