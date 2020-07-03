#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        int a,b;
        cin >> a >> b;

        cout << a + b << "\n";
    }
    return 0;
}
