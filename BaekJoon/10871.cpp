#include <iostream>

using namespace std;

int main() {
    int num;
    int threshold;
    
    cin >> num >> threshold;
    
    for (int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        if (tmp < threshold) {
            cout << tmp << " ";
        }
    }
    
    cout << endl;
    return 0;
}
