#include <iostream>

using namespace std;

int main() {
    int curr;
    int prev = -1;
    int status_ = 2;
    for (int i = 0; i < 8; i++) {
        cin >> curr;
        if (prev != -1) {
            if (curr > prev) {
                if (status_ < 1) {
                    status_ = 0;
                    break;
                }
                status_ = 1;
            }
            else  {
                if (status_ == 1) {
                    status_ = 0;
                    break;
                }
                status_ = -1;
            }
        }
        prev = curr;
    }
    
    if (status_ == -1) cout << "descending" << endl;
    if (status_ == 0) cout << "mixed" << endl;
    if (status_ == 1) cout << "ascending" << endl;
    return 0;
}
