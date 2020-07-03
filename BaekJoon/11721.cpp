#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    cin >> line;
    int index = 0;

    while (index < line.length()) {
        if (line.length() - index < 10) {
            for (int i = index; i < line.length(); i++) {
                cout << line[i];
            }
            cout << endl;
            break;
        } else {
            for (int i = 0; i < 10; i++) {
                cout << line[index + i];
            }
            cout << endl;
            index += 10;
        }
    }

    return 0;
}
