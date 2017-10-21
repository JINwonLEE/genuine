#include <iostream>

using namespace std;

void check_num(int val, int& sum, bool& check) {
    if (val == 1) {
        return;
    }
    for (int i = 2; i < val; i++) {
        if (val % i == 0) {
            return;
        }
    }
    check = true;
    sum += val;;
}

int main() {
    int N, M;
    int min = 10001;
    int sum = 0;
    bool check = false;
    bool check_ = false;
    cin >> N >> M;
    
    for (int i = N; i <= M; i++) {
        check_num(i, sum, check);
        if (check) {
            check_ = true;
        }
        if (check && min > i) {
            min = i;
        }   
        check = false;
    }
    if (!check_) {
        cout << "-1" << endl;
    }
    else {
        cout << sum << endl;
        cout << min << endl;
    }
        
    return 0;
}
