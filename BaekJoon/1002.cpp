#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int test_case;

    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        int x1, y1, r1, x2, y2, r2;

        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        int big_r = r1 > r2 ? r1 : r2;
        int small_r = r1 > r2 ? r2 : r1;

        if (dist <= big_r) {
            if (x1 == x2 && y1 == y2 && r1 == r2) cout << -1 << endl;
            else if (dist + small_r < big_r) cout << 0 << endl;
            else if (dist + small_r == big_r) cout << 1 << endl;
            else if (dist + small_r > big_r) cout << 2 << endl;
        } else {
            if (dist == small_r + big_r) cout << 1 << endl;
            else if (dist > small_r + big_r) cout << 0 <<endl;
            else if (dist < small_r + big_r) cout << 2 << endl;
        }
    }
    return 0;
}
