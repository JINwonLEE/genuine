#include <iostream>

using namespace std;

int main() {
    int n;
    int test_case;
    cin >> test_case;

    int z_count[41];
    int o_count[41];

    z_count[0] = 1;
    o_count[0] = 0;
  
    z_count[1] = 0;
    o_count[1] = 1;

    for (int i = 2; i <= 41; i++) {
        z_count[i] = z_count[i-1] + z_count[i-2];
        o_count[i] = o_count[i-1] + o_count[i-2];
    }

    for (int i = 0; i <test_case; i++) {
        cin >> n;
        cout << z_count[n] << " " << o_count[n] << endl;
    }

    return 0;
}
