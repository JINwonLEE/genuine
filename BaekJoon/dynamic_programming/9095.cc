#include <iostream>

using namespace std;

int main() {
    int test_case = 0;

    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        int n = 0;
        cin >> n;

        int count[12] = {0};
        count[0] = 1;

        for (int i = 1; i <= n; i++) {
            if (i - 1 >= 0) {
                count[i] += count[i - 1];
            }
            if (i - 2 >= 0) {
                count[i] += count[i - 2];
            }
            if (i - 3 >= 0) {
                count[i] += count[i - 3];
            }
        }

        cout << count[n] << endl;
    }

    return 0;
}
