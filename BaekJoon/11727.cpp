#include <iostream>

using namespace std;

int main() {
    int n = 0;

    cin >> n;
    long long count[1001] = {0};
    count[1] = 1;
    count[2] = 3;

    for (int i = 3; i <= n; i++) {
        if (i - 2 >= 1) {
            count[i] += 2 * count[i - 2];
        }

        if (i - 1 >= 1) {
            count[i] += count[i - 1];
        }

        if (count[i] > 10007) {
            count[i] = count[i] % 10007;
        }
    }

    cout << count[n] << endl;

    return 0;
}
