#include <iostream>
using namespace std;

class Matrix {
private:
    double* m; // points to a single vector of double...
public:
    // write constructor, destructor, copy constructor, operator =
    Matrix(int rows, int cols) : m(m) {
        for(int i = 0; i < rows; i++ ){
            for(int j = 0; j < cols; j++){
                m[i][j] = 0;
            }
        }
    }

    Matrix(int rows, int cols, double val) :m(m) {
        for(int i = 0; i < rows; i++ ){
            for(int j = 0; j < cols; j++){
                m[i][j] = val;
            }
        }
    }

    double  operator ()(int i, int j) const {
        return m[i][j];
    }
    double&  operator ()(int i, int j) {
        return m[i][j];
    }
    Matrix(Matrix&& orig) {
    m = orig.m;
        rows = orig.rows;
        cols = orig.cols;
        orig.m = nullptr;
    }

    friend ostream& operator <<(ostream& s, const Matrix& str){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cout << m[i][j] <<' ';
            }
            cout <<'\n';
        }
        return s;
    }

    friend Matrix operator +(const Matrix& a, const Matrix& b) {
        // test if the two matrices are equal in size!!!
        if(a.i != b.i || a.j != b.j){
            cout << "a,b are not same size!" << '\n';
            break;
        }
        Matrix ans(a.i + b.i, a.j + b.j);
        return ans;
    }

    //friend Matrix operator =(const )
    void operator =(const Matrix& a, const Matrix& b) {
        Matrix ans(a.operator (i)(j) = b.operator (i)(j));
    }
};


int main() {
    Matrix m1(3, 4); // zeros
    Matrix m2(2, 3, 1.5); // fill with 1.5
    cout << m1 << '\n';
    /*
        0   0   0   0
        0   0   0   0
        0   0   0   0
    */
    cout << m1(0, 1) << '\n';
    m1(0,1) = 5.5;
    Matrix m3 = m1 + m1;
    Matrix m4 = m3;  //copy constructor
    cout << m4 << '\n';
    m4(1,2) = 11.2;
    m3 = m4; // operator =
}
