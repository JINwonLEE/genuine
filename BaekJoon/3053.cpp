#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    double r;
    
    cin >> r;
    
    cout << setprecision(6) << fixed << r * r * M_PI << endl;
    cout << setprecision(6) << fixed << r * r * 2 << endl;
    return 0;
}
