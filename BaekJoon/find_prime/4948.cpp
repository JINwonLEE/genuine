#include <iostream>

using namespace std;

int main() {
    int value = -1;
    int sum;
    bool check;
    
    while (true) {
        cin >> value;
        if (value == 0) {
            break;
        }
        sum = 0;
        for (int i = value + 1; i <= value * 2; i++) {
            if (i == 1) {
                continue;
            }
            check = true;
            for (int j = 2; j*j <= i; j++) {
                if (i % j == 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                sum++;
            }
        }
        cout << sum << "\n";
    }
            
    return 0;
}
