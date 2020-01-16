#include <iostream>

using namespace std;

int main() {
    int test_case;

    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        int a, b;
        cin >> a >> b;

        cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << endl;
    }
    return 0;
}

