#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < 2 * N - 1; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            if ((j >= i && j < 2 * N - 1 - i) || (i >= N && j > 2 * N - 1 - (i + 2) && j <= i)) {
                cout << "*";
            } else if ( j <= N) { 
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
