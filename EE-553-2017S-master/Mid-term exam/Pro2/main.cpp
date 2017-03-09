//Author: Guoli Sun ID:10395608
#include <iostream>
using namespace std;

class Complex{
private:
    double r, i;
public:
    Complex(double r, double i):r(r), i(i){}
    Complex():r(0), i(0){}
    // two different signals' judgement
    friend ostream& operator <<(ostream& s, Complex v){
        if(v.i>=0){
            s << v.r << "+" << v.i << "i" ;
            return s;
        }else{
            s << v.r << "-" << -v.i << "i" ;
            return s;
        }
    }

    Complex operator +(Complex b){
        return Complex(r+b.r, i+b.i);
    }

    friend Complex operator -(Complex a){
        return Complex(-a.r, -a.i);
    }
};

int main() {
 Complex c1;
 cout << c1 << '\n'; // should print 0+0i
 double r,i;
 cin >> r >> i;
 Complex c2(r,i);
 cout << c2 + c2 << '\n';
 cout << -c2 << '\n';
}
