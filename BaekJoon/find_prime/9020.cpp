#include <iostream>

using namespace std;

bool isPrime(int a) {
    if (a == 1) {
        return false;
    }
    for (int i = 2; i*i <= a; i++) {
        if (a % i == 0) { 
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int test_;
        cin >> test_;
        int mid = test_ >> 1;
        int k = mid;
        int j = mid;
        for (; j < test_; k--, j++) {
            if (isPrime(k) && isPrime(j)) {
                cout << k << " " << j << "\n";    
                break;
            }
        }
    }
    return 0;
}
