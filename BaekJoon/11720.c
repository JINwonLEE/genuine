#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string nums;
    cin >> N;
    cin >> nums;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += nums[i] - '0' ;
    }
    cout << sum << endl;

    return 0;
}
