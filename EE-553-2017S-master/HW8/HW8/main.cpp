//Guoli Sun
//10395608
#include <iostream>
using namespace std;

class Matrix {
private:
  double* m;
  int rows;
  int cols;
public:
    Matrix(int rows, int cols) : rows(rows),cols(cols) {
    double area[rows * cols];
    int a2 = rows * cols;
    m = new double[rows * cols];
    for(int i =  0;i < a2; i++)
      m[i] = 0;
    }
  Matrix(int rows, int cols, double fill) : rows(rows),cols(cols) {
    double area[rows * cols];
    int a2 = rows * cols;
    m = new double[rows * cols];
    for(int i =  0; i < a2; i++)
      m[i] = fill;
  }

  Matrix(Matrix& orig) {
    m = orig.m;
    rows = orig.rows;
    cols = orig.cols;
    orig.m = nullptr;
  }

  ~Matrix(){
    delete[] m;
  }

  Matrix(const Matrix& orig) : m(new double[orig.cols * orig.rows]),rows(orig.rows),cols(orig.cols){
        for(int i = 0; i < cols*rows; i++)
            m[i] = orig.m[i];
    }

    double  operator ()(int i, int j) const {
        return m[i * this->cols + j];
    }

    double&  operator ()(int i, int j) {
    return m[i * this->cols + j];
    }

  void operator =(const Matrix& orig){
      delete [] m;
      m = new double[orig.rows * orig.cols];
      rows = orig.rows;
      cols = orig.cols;
      for (int i = 0; i < rows * cols; i++)
        m[i] = orig.m[i];
    }

  friend Matrix operator +(const Matrix& a, const Matrix& b) {
    if (a.cols != b.cols && a.rows != b.rows){
      cout << "the size of these matrices is not equal." << endl;
      return a;
    }

    else{
        Matrix ans(a.rows, a.cols);
      for(int i = 0; i < a.rows; i++){
        for(int j =0; j < a.cols; j++){
          ans.m[i * ans.cols + j] = a.m[i * ans.cols  + j] + b.m[i*ans.cols + j];
        }
      }
          return ans;
    }
    }

  friend ostream& operator << (ostream& s, const Matrix& ref){
    for(int i = 0; i < ref.rows; i++){
      s << '\n';
      for(int j = 0; j < ref.cols; j++){
        s << ref.m[i * ref.cols + j] << " ";
      }
    }
    return s;
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
