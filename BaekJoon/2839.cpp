#include <iostream>

using namespace std;

int main() {
    int N, num;
    cin >> N;
    num = 0;
    int rest = N % 5;
    int q = N / 5;
    
    while (q >= 0) {
        if (rest % 3 == 0) {
            num = rest / 3;
            rest = 0;
            break;
        }
        else {
            rest += 5;
            q--;
        }
    }
    if (rest == 0)
        cout << num + q << endl;
    else
        cout << -1 << endl;
    return 0;
}
