#include <iostream>

using namespace std;

int main() {
    int num;
    int k = 0;
    cin >> num;
        
    int first = 2;
    int second  = 7;
    if (num == 1) {
        cout << 1 << endl;
        return 0;
    }
    while (first > num || second < num) {
        k++;
        first = k*k*3 + 3*k + 2;
        second = k*k*3 + 9*k + 7;
    }
    
    cout << 2 + k << endl;
    return 0;
}
