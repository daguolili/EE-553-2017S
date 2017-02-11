//Vec3d
//Author:Guoli Sun ID:10395608
#include <iostream>
using namespace std;

class Vec3d{
private:
    double num1, num2, num3;
public:
    Vec3d(double x = 0.0, double y = 0.0, double z = 0.0):num1(x),num2(y),num3(z){}

    Vec3d add(const Vec3d b) const{
        return Vec3d(num1 + b.num1, num2 + b.num2, num3 + b.num3);
    }

    double dot(const Vec3d b) const{
        double ans = num1 * b.num1 + num2 * b.num2 + num3 * b.num3;
        return ans;
    }

    Vec3d operator +(Vec3d b) const{
        return Vec3d(num1 + b.num1, num2 + b.num2, num3 + b.num3);
    }

    friend Vec3d operator *(const Vec3d &a, const double &b) ; // 利用友元函数实现交换律 记得加const 以及地址符&
    friend Vec3d operator *(const double &b, const Vec3d &a) ;

    friend ostream& operator <<(ostream& s, Vec3d v);
};

ostream& operator <<(ostream& s, Vec3d v){
    s << "(" << v.num1 << ", " << v.num2 << ", " << v.num3 << ")";
    return s;
};

Vec3d operator *(const Vec3d &a, const double &b){
    return Vec3d(a.num1 * b, a.num2 * b, a.num3 * b);
}

Vec3d operator *(const double &b, const Vec3d &a){
    return Vec3d(a.num1 * b, a.num2 * b, a.num3 * b);
}

int main() {
    const Vec3d a(1.0, 2, 2.5); //(1.0, 2.0, 2.5) (x,y,z)
    cout << a << '\n';
    Vec3d b(5.0);         //(5.0, 0.0, 0.0)
    Vec3d c = a + b;
    cout << c << '\n';
    Vec3d c2 = a.add(b);   // call a method
    cout << c2 << '\n';
    double d = a.dot(b); //  dot product = a.x*b.x + a.y*b.y + a.z*b.z
    cout << d << '\n';

    Vec3d e = a * 2;   //scalar multiplication
    cout << e << '\n';
    Vec3d f = 2 * a;   //scalar multiplication
    cout << f << '\n';

}

