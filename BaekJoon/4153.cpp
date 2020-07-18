#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void checkRight(int max, int y, int z) {
    if (max * max == y * y + z * z) {
        cout << "right" << endl;
    } else {
        cout << "wrong" << endl;
    }
}

int main() {
    while (true) {
        int x, y, z;

        cin >> x >> y >> z;

        if (x == 0 && y == 0 && z == 0) {
            break;
        }

        int max_val = max(x, max(y, z));
        if (max_val == x) {
            checkRight(x, y, z);
        } else if (max_val == y) {
            checkRight(y, x, z);
        } else {
            checkRight(z, y, x);
        }
    }
    return 0;
}
