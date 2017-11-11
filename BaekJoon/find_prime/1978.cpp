#include <iostream>
#include <math.h>
using namespace std;

void check_num(int val, int& sum) {
    if (val == 1) {
        return;
    }
    for (int i = 2; i < val; i++) {
        if (val % i == 0) {
            return;
        }
    }
    sum++;
}

int main() {
    int num;
    cin >> num;
    int sum = 0;
    
    int val;
    for (int i = 0; i < num; i++) {
        cin >> val;
        check_num(val, sum);
    }

    cout << sum << endl;
        
    return 0;
}


