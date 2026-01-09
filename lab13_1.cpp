#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double a[], int b, double c[]){
    double sum = 0;
    double sumofsquares = 0;
    double prod = 1;
    double HarmoSum = 0;
    double Min = a[0];
    double Max = a[0];
    for (int i = 0; i < b; i++) {
        sum += a[i];
        sumofsquares += a[i] * a[i];
        prod *= a[i];
        HarmoSum += 1.0 / a[i];
        if (a[i] > Max) Max = a[i];
        if (a[i] < Min) Min = a[i];
    }
    
    double ArithMean = sum / b;
    
    double stvar = 0;
        for (int i = 0; i < b; i++) {
            stvar += (a[i] - ArithMean) * (a[i] - ArithMean);
    }
    
    double stdev = sqrt(stvar / b);
    
    double GeoMean = 0;
    GeoMean = pow(prod, 1.0 / b);
    
    double HarmoMean = 0;
    HarmoMean = double(b / HarmoSum);
    c[0] = ArithMean;
    c[1] = stdev;
    c[2] = GeoMean;
    c[3] = HarmoMean;
    c[4] = Max;
    c[5] = Min;
}
