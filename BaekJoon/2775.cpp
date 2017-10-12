#include <iostream>

int sum(int k_, int n_);

using namespace std;

int main() {
    int test_case, k, n;
    cin >> test_case;
    
    for (int i = 0; i < test_case; i++) {
        cin >> k >> n;
        int num = sum(k, n); 
        cout << num << endl;
    }
    return 0;
}

int sum(int k_, int n_) {
    int num_ = 0;
    if (k_ == 0) {
        num_ = n_;
        return num_;
    }
    else {
        for (int i = 1; i <= n_; i++) {
            num_ += sum(k_ - 1, i);
        }   
    }
    return num_;
}
