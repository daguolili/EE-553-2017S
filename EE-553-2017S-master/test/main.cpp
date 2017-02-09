#include <iostream>
using namespace std;

int x;
void f(int x){
    static int y=1;
    x++;
    cout <<x<< ::x << y++;
    ::x--;
}

int main()
{
    int x =2;
    f(x);
    cout << x;
    f(x);
}
