#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int num = 666;
    int count = 0;
    while (true) {
        string num_string = to_string(num); 
        if (num_string.find("666") != string::npos) {
            count++;
        }
        if (count == N) {
            cout << num << endl;
            break;
        }
        num++;
    }
    return 0;
}
