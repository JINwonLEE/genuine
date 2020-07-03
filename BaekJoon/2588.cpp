#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    int hnum, tnum, onum;

    cin >> num1;
    cin >> num2;

    onum = num2 % 10;
    tnum = (num2 / 10) % 10;
    hnum = (num2 / 100) % 10;

    cout << num1 * onum << endl; 
    cout << num1 * tnum << endl; 
    cout << num1 * hnum << endl; 
    cout << num1 * num2 << endl;

    return 0;
}
