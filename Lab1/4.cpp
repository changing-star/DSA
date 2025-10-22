#include <iostream>
using namespace std;

float computeGaussSum(int n){
    return n*(n+1)/2;
}

float sumOfSquares(int n){
    return n*(n+1)*(2*n+1)/6;
}

//https://en.wikipedia.org/wiki/Harmonic_number
float computeHarmonicNumber(int n){
    float res = 0;
    for(int i = 1; i<=n;i++){
        res += (float)1/i;
    }
    return res;
}


int main(){
    float gaussSum  = computeGaussSum(10);
    float sumOfSquaresNum  = sumOfSquares(20);
    float harmonicNum  = computeHarmonicNumber(30);

    cout << "Gaussian sum: " << gaussSum << endl;
    cout << "Sum of squares: " << sumOfSquaresNum << endl;
    cout << "Harmonic nth number: " << harmonicNum << endl;

    return 0;

};

