#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int case_;
    cin >> case_;

    cin.ignore();
    for (int i = 0; i < case_; i++) {
        string test;
        stack<char> st;
        bool check = true;
        getline(cin, test);
        for (int i = 0; i < test.length(); i++) {
            if (test[i] == '(') {
                st.push(test[i]);
            }
            else {
                if (st.empty()) {
                    check = false;
                    break;
                }
                else {
                    st.pop();
                }
            }
        }
        
        if (check && st.empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
