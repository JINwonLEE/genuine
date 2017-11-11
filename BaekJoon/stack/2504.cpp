#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string p;
    cin >>p;
    int sum = 0;
    stack<int> st;
    bool wrong = false; // '(' = -1, ')' = -2, '[' = -3, ']' = -4

    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') {
            st.push(-1);
        }
        else if (p[i] == ')') {
            if (st.top() != -1 && st.top() < 0) {
                wrong = true;
                sum = 0;
                break;
            }
            else {
                if (st.top() == -1) {
                    st.pop();
                    st.push(2);
                }
                else {
                    int val = 0;
                    while (st.top() != -1) {
                        if (st.top() > 0) {
                            val += st.top();
                            st.pop();
                        }
                        else {
                            wrong = true;
                            sum = 0;
                            break;
                        }
                    }
                    if (wrong) break;
                    val *= 2;
                    st.pop();
                    if (st.empty()) {
                        sum += val;
                    }
                    else {
                        st.push(val);
                    }
                }
            }
        }
        else if (p[i] == '[') {
            st.push(-3);
        }
        else if (p[i] == ']') {
            if (st.top() != -3 && st.top() < 0) {
                wrong = true;
                sum = 0;
                break;
            }
            else {
                if (st.top() == -3) {
                    st.pop();
                    st.push(3);
                }
                else {
                    int val = 0;
                    while (st.top() != -3) {
                        if (st.top() > 0) {
                            val += st.top();
                            st.pop();
                        }
                        else {
                            wrong = true;
                            sum = 0;
                            break;
                        }
                    }
                    if (wrong) break;
                    val *= 3;
                    st.pop();
                    if (st.empty()) {
                        sum += val;
                    }
                    else {
                        st.push(val);
                    }
                }
            }
        }
    }
    while (!st.empty()) {
        if (st.top() > 0) {
            int val = st.top();
            st.pop();
            sum += val;
        }
        else {
            wrong = true;
            sum = 0;
            break;
        }
    }

    cout << sum << "\n";
    return 0;
}
