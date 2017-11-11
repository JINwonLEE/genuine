#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    queue<char> plus_minus;
    stack<int> number;
    bool isPossible = true;
    int num;
    int count_number = 0; 
    cin >> num;
    int *arr = new int[num];

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < num; i++) {
        if (count_number < arr[i]) {
            while (count_number < arr[i]) {
                count_number++;
                number.push(count_number);
                plus_minus.push('+');
            }
            number.pop();
            plus_minus.push('-');
        }
        else {
            if (number.top() < arr[i]) {
                isPossible = false;
            }
            else {
                number.pop();
                plus_minus.push('-');
            }
        }
    }

    if (isPossible) {
        while (!plus_minus.empty()) { 
            cout << plus_minus.front() << "\n";
            plus_minus.pop();
        }
    }
    else {
        cout << "NO\n";
    }

     
    delete [] arr;
    return 0;
}

