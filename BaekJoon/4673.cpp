#include <iostream>

int d_n(int n);

using namespace std;

int main() {
    bool check[10000] = {false,};
    
    for (int i = 1; i < 10000; i++) {
        if (d_n(i) <= 10000) check[d_n(i)] = true;
        if (!check[i]) cout << i << "\n";
    }
    
    return 0;
}

int d_n(int n) {
    int ret = n;
    while (n != 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
