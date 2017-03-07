#include <iostream>
using namespace std;

int main(){
    int a[10];
    int *b = a;
    for (int i = 0; i < 10; i++){
        *b++ = 0;
        cout << a[i] << " ";
    }
    return 0;
}
