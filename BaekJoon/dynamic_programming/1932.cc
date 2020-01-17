#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;

    cin >> n;

    int numbers[500][500] = {0};
    int sum[501][501] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> numbers[i][j];
            sum[1][j] = numbers[i][j];
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            sum[i][j] =
                numbers[n - i][j] + max(sum[i - 1][j], sum[i - 1][j + 1]);
        }
    }

    cout << sum[n][0] << endl;

    return 0;
}
