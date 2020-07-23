#include <iostream>

using namespace std;

bool isValid(int i, int j, int n) {
    bool result = true;
    if (n == 3) {
       if (i % 3 == 1 && j % 3 == 1) {
           result = false;
       }
       return result;
    }
    int i_remain = i % n;
    int j_remain = j % n;

    if (i_remain < n / 3 * 2 && i_remain >= n / 3 && j_remain < n / 3 * 2  && j_remain >= n / 3) {
        result = false;
    }

    return result && isValid(i, j, n / 3);
}


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isValid(i, j, n)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
