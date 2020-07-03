#include <iostream>

using namespace std;

int main() {
    int N;
    int mult = 1;
    for (int i = 0; i < 3; i++) {
        cin >> N;
        mult *= N;
    }
    
    int count[10] = {0,};
    while (mult > 0) {
        int d = mult % 10;
        count[d]++;
        mult /= 10;       
    }
    
    for (int i = 0 ; i < 10; i++) {
        cout << count[i] << endl;
    }
        
    return 0;
}
