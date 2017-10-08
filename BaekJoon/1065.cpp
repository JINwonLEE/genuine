#include <iostream>

bool check (int n);

using namespace std;

int main() {
    int count = 0;
    int N;
    cin >> N;
   
    for (int i = 1; i <= N; i++) {
        if (check(i)) count++;
    }

    cout << count << endl;
    return 0;
}

bool check (int n) {
    if (n < 100) return true;
    int low = n % 10;
    n /= 10;
    int high = n % 10;
    n /= 10;
    int d = low - high;
    
    while (n > 0) {
        low = high;
        high = n % 10;
        n /= 10;
        if (d != low - high) return false;
    }
    return true;
}
