#include <iostream>

using namespace std;


int main() {
    int N;

    cin >> N;

    int result = 0;
    for (int i = 1; i < N; i++) {
        int tmp = i;
        int sum = tmp;
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == N) {
            result = i;
            break;
        }
    }
    cout << result << endl;

    return 0;
}
