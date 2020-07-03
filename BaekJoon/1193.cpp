#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    int line_sum = 1;
    int up = 0;
    int down = 0;
    bool go_up = false;
    while ( line_sum * (line_sum + 1) /2 < num ) {
        line_sum++;
    }
    line_sum++;
    if (line_sum % 2 == 1) {
        up = 1;
        down = line_sum - up;
    }
    else {
        go_up = true;
        down = 1;
        up = line_sum - down;
    }
    int diff = num - (line_sum - 2) * (line_sum - 1) / 2 - 1;
    while (diff > 0) {
        if (go_up) {
            down++;
            up--;
        }
        else {
            down--;
            up++;
        }
        diff--;
    }
 
    cout << up << "/" << down << endl;
    
    return 0;
}
