#include <iostream>

using namespace std;

int main() {
    int M, N, val;
    bool check;
    cin >> M >> N;
        
    for (int i = M; i <= N; i++) {
        if (i == 1) {
            continue;
        }
        val = i;
        check = true;
        for (int j = 2; j*j <= val; j++) {
            if (val % j == 0) {
                check = false;
                break;
            }
        }
        if (check) {
            cout << val << "\n";
        }
    }   
    return 0;
}
