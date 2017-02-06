//Array statistics
//Author:Guoli Sun ID:10395608
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //open the file
    int arr[10], sum = 0, avg;
    ifstream infile;
    infile.open("/Users/sunguoli/github/EE-553-2017S-master/HW2/HW2f/2f.dat");

    //Check for Error

    if(infile.fail()){
        cout << "Error Opening File" << endl;
        exit(1);
    }

    // use array to store the value in 2f.dat
    for(int i = 0; i < 10 ;i++)
            infile>>arr[i];
    infile.close();

    //get the n
    int n = arr[0];
    cout << n << endl;

    //calculate the average of the array
    for(int i = 1; i < n + 1;i++){
        cout << arr[i] << endl;
        sum += arr[i];
    }
    avg = sum / n;
    cout << "The average of the array is " << avg << endl;
    return 0;
}
