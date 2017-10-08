#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < 9; i++)
        cout << N << " * " << i+1 << " = " << (i+1)*N << "\n";
    
    return 0;
}
