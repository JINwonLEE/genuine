#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;
    int new_ = N;
    do {
        int ten = new_ / 10;
        int one = new_ % 10;
        
        new_ = (ten + one) % 10 + one * 10;
        count++;
    }while (new_ != N);

    cout << count << endl;
    return 0;
}
