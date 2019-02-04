#include <iostream>


using namespace std;

int main() {
    int num;
    cin >> num;
    int count[10000001];
    fill_n(count, 10000001, 0);
    
    int val;
    for (int i = 0; i < num; i++) {
        cin >> val;
        count[val]++;
    }
   
    for (int i = 1; i < 10001; i++) {
        count[i] += count[i-1];
    }
    
    for (int i = 1; i < 10001; i++) {
        int diff = count[i] - count[i-1];
        while (diff > 0) {
            cout << i << "\n";
            diff--;
        } 
    }
    

    return 0;
}
