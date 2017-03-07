/*
    Author: Guoli Sun  ID : 10305608
    365 days in a year
    LEAP YEAR: any year divisible by 4 --> LEAP
    EXCEPT:   if year divisible by 100 --> NOT LEAP
    EXCEPT:   if year divisible by 400 --> LEAP
    year = 365.2425 days
    2000 LEAP
    2004 LEAP
    2100 NOT LEAP
    J2000 = Jan. 1, 2000 = 0
    Jan. 2, 2000 = 1
    Jan. 3, 2000 = 2
https://en.wikipedia.org/wiki/Julian_day
http://aa.usno.navy.mil/faq/docs/JD_Formula.php
Look it up, cite it, feel free to use it.  Just make it object oriented.
 */

#include <iostream>
#include <cmath>
using namespace std;

class JulianDate {
private:
    double jday;

//JD =	367K - <(7(K+<(M+9)/12>))/4> + <(275M)/9> + I + 1721013.5 + UT/24 - 0.5sign(100K+M-190002.5) + 0.5
//The sign function serves to extract the algebraic sign from a number.
//The truncation function < > extracts the integral part of a number.
public:
  JulianDate(int year, int month, int day, double UT, double minute, double second) : jday(jday){
        minute += second / 60;
        UT += minute / 60;
        if((100 * year + month - 190002.5)>0)
            jday -=.5;
        else
            jday +=.5;
        jday += 367 * year - trunc(7*(year+((month + 9) / 12)))/4 + trunc((275 * month) / 9) + day + 1721013.5 + UT/24 + 0.5;
    }

    JulianDate(int year, int month, int day) : jday(jday){
        double UT = 0;
        if((100 * year + month - 190002.5)>0)
            jday -= 0.5;
        else
            jday += 0.5;
        jday += 367 * year - trunc(7*(year+((month + 9) / 12)))/4 + trunc((275 * month) / 9) + day + 1721013.5 + UT/24 + 0.5;
    }

    JulianDate(double a) : jday(a){}

    friend ostream& operator << (ostream& s, JulianDate d){
        return s << d.getYear() << d.getMonth() << d.getDay() << d.getHour() << d.getMin() << d.getSec();
    }

    friend double operator - (JulianDate a, JulianDate b){
        return (a.jday - b.jday);
    }

    friend JulianDate operator + (JulianDate a, double b){
        return JulianDate(a.jday + b);
    }

/*  according to https://en.wikipedia.org/wiki/Julian_day, we could calculate what we want
    For Gregorian calendar:

    1. f = J + j + (((4 × J + B) div 146097) × 3) div 4 + C
    For Julian or Gregorian, continue:

    2. e = r × f + v
    3. g = mod(e, p) div r
    4. h = u × g + w
    5. D = (mod(h, s)) div u + 1
    6. M = mod(h div s + m, n) + 1
    7. Y = (e div p) - y + (n + m - M) div n
*/
    int getYear() const{
        int L = jday+68569;
        int N = 4*L/146097;
        L = L-(146097*N+3)/4;
        int I= 4000*(L+1)/1461001;
        L = L-1461*I/4+31;
        int J = 80*L/2447;
        int K = L-2447*J/80;
        L = J/11;
        J = J+2-12*L;
        I = 100*(N-49)+I+L;
        return I;
    }
    int getMonth() const{
        int L = jday+68569;
        int N = 4*L/146097;
        L = L-(146097*N+3)/4;
        int I = 4000*(L+1)/1461001;
        L = L-1461*I/4+31;
        int J = 80*L/2447;
        int K = L-2447*J/80;
        L = J/11;
        J = J+2-12*L;
        I = 100*(N-49)+I+L;
        return J;
    }
    int getDay() const{
        int L = jday+68569;
        int N = 4*L/146097;
        L = L-(146097*N+3)/4;
        int I = 4000*(L+1)/1461001;
        L = L-1461*I/4+31;
        int J = 80*L/2447;
        int K = L-2447*J/80;
        L = J/11;
        J = J+2-12*L;
        I = 100*(N-49)+I+L;
        return K;
    }
    int getHour() const{
        double dec = jday - int(jday);
        return int(dec * 24);
    }
    int getMin() const{
        double dec = jday - int(jday) - getHour()/24.0;
        return int(dec * 24 * 60);
    }
    int getSec() const{
        double dec = jday - int(jday) - getHour()/24.0 - getMin()/60.0;
        return int(dec + 24 * 60 * 60);
    }
};


int main() {
    const JulianDate d1(2017, 2, 13, 20, 00, 00);
    const JulianDate d1b(2017, 2, 13, 22, 00, 00);

    cout << d1b - d1 << '\n'; // 2 hours = 2/24 day

    const JulianDate tomorrow = d1 + 1;
    cout << tomorrow; // 2017 2 14 20 00 00
    cout << tomorrow - d1 << '\n';
    // hh:mm:ss  20/24  20/24.0
    const JulianDate d2(2017, 2, 19); // 00:00:00
  const JulianDate d3 = d2 + 3; // what is it 3 days later?
    double days   = d3 - d1;

    int year = d3.getYear();
    int month = d3.getMonth();
    int day = d3.getDay();
    int hour = d3.getHour();
    int min = d3.getMin();
    int sec = d3.getSec();
    cout << d1 << '\n';
    cout << d2 << '\n';
    cout << d3 << '\n';
    cout << year << " " << month << " " << day <<
        hour << " " << min << " " << sec << '\n';
    // Not every operation makes sense!
    //	JulianDate d5 = d3 * d1;
    JulianDate torture(2017, 2, 27); // 00:00:00
    for (int i = 0; i < 3; i++) {
        cout << torture.getYear() << " " << torture.getMonth() << " " << torture.getDay() << '\n';
        torture = torture + 1;
    }
}
