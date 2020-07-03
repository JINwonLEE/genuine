#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N;
    
    cin >> N;
    double max = 0;
    double sum;
    double num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (max < num)
            max = num;
        sum += num;
    }
    
    cout <<fixed << setprecision(2) << (double)floor(sum /(max*N)*10000 + 0.5)/100 << endl;
    
       
    return 0;
}
