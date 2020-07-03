#include <iostream>
#include <string>

using namespace std;

int main() {
    int case_;
    cin >> case_;
    
    for (int i = 0; i < case_ ; i++) {
        int num;
        string st;
        cin >> num;
        cin >> st;
        for (int j = 0; j < st.length(); j++) {
            for (int k = 0; k < num; k++) {
                cout << st[j];
            }
        }
        cout << "\n";
    
    }
    
    return 0;
}
