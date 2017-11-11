#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

int main() {
    int stack_[10001];
    fill_n(stack_, 10001, -1);
    int orders;
    int size = 0;
    int top = -1;
    cin >> orders;
    
    string str;
    cin.ignore();
    for (int i = 0; i < orders; i++) {
        getline(cin, str);
        string t_str = str.substr(0, str.find(" "));
        if (t_str == "push") {
            string t_str2 = str.substr(t_str.length() + 1, str.find("\n"));
            int num;
            istringstream(t_str2) >> num;
            stack_[++top] = num;
            size++;
        }
        else if (t_str == "pop") {
            if (top == -1) {
                cout << "-1\n";
                continue;
            }
            else {
                cout << stack_[top--] << "\n";
            }
            size--;
        }
        else if (t_str == "size") {
            cout << size << "\n";
        }
        else  if (t_str == "empty") {
            if (top == -1) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (t_str == "top") {
            if (top == -1) {
                cout << "-1\n";
            }
            else {
                cout << stack_[top] << "\n";
            }
        }
    }
    return 0;
}
