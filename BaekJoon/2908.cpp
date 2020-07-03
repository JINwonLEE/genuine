#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string first, second;
    
    cin >> first >> second;

    reverse(first.begin(), first.end());
    reverse(second.begin(), second.end());
    int first_ = atoi(first.c_str());
    int second_ = atoi(second.c_str());
    
    if (first_ < second_) {
        cout << second_ << endl;
    }
    else {
        cout << first_ << endl;
    }
    
    return 0;
}

