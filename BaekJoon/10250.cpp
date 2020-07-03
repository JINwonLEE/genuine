#include <iostream>

using namespace std;

int main() {
    int test_case, h, w, N, q, rest;
    cin >> test_case;
    
    for (int i = 0; i < test_case; i++) {
        cin >> h >> w >> N;
        q = N / h;
        if (h * q < N) {
            q++;
        }
        
        rest = N % h;
        if (rest == 0) {
            rest = h;
        }
        int room = rest * 100 + q;
        cout << room << endl;       
    }
    
    return 0;
}
