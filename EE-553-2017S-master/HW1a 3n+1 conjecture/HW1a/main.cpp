// 3n+1 conjecture program
// Author: Guoli Sun ID: 10395608
#include <iostream>
using namespace std;

int main()
{
   int n;
   cin >> n;
   cout << n << " ";
   while(n != 1 && n > 0){
       if(n % 2 == 1){      //if it's odd, multiply by 3 and add 1
           n = n * 3 + 1;
           cout << n << " ";
       }
       else{        //if it's even divide by 2
           n = n / 2;
           cout << n << " ";
       }
   }
   return 0;
}
