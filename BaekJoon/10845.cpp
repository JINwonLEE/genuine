#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

int main() {
    int queue_[10001];
    fill_n(queue_, 10001, -1);
    int orders;
    int size = 0;
    int back = -1;
    int front = 0;
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
            queue_[++back] = num;
            size++;
        }
        else if (t_str == "pop") {
            if (size == 0) {
                cout << "-1\n";
                continue;
            }
            else {
                cout << queue_[front++] << "\n";
                queue_[front - 1] = -1;
            }
            size--;
        }
        else if (t_str == "size") {
            cout << size << "\n";
        }
        else  if (t_str == "empty") {
            if (size == 0) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (t_str == "front") {
            if (size == 0) {
                cout << "-1\n";
            }
            else {
                cout << queue_[front] << "\n";
            }
        }
        else if (t_str == "back") {
            if (size == 0) {
                cout << "-1\n";
            }
            else {
                cout << queue_[back] << "\n";
            }
        }
    }
    return 0;
}
