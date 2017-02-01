//Multiple primes
//Author:Guoli Sun ID:10395608
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
        //cout << i;
        if(p % i ==0 )
            return false;
        else
            return true;
    }
}

// function for counting how many primes in the array
int countPrimes(unsigned long long a, unsigned long long b){
    int count = 0;
    for(unsigned long long i = a; i <= b; i++){
        if(isPrime(i)){
            count++;
        }
    }
    return count;
}

int main()
{
    unsigned long long a, b;
    cout << "Please enter in two numbers :";
    cin >> a >> b;
    int sum = countPrimes(a,b);
    cout << "there have " << sum << " primes in the range[" << a << "," << b << "] inclusive.\n";
    return 0;
}
