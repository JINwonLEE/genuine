#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = N; i > 0; i--) {
        for (int j = N; j > i; j--) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout <<"*";
        }
        cout <<"\n";
    }
    return 0;
}
