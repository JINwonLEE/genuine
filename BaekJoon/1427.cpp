#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string N;
    cin >> N;
    int* arr = new int[N.length()];
    
    for (int i = 0; i < N.length(); i++) {
        arr[i] = (int)(N[i] - '0');
    }
    
    sort(arr, arr+N.length());
    
    for (int i = N.length() - 1; i >= 0; i--) {
        cout << arr[i];
    }
    return 0;
}
