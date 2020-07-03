#include <iostream>

using namespace std;

int main() {
    int A, B, V;

    cin >> A >> B >> V;
    int count = (V - B - 1) / (A - B) + 1;

    cout << count << endl;

    return 0;
}
