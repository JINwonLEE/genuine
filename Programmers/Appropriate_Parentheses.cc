#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for (auto ele : s) {
        if (ele == '(') {
            st.push(ele);
        } else {
            if (st.size() == 0) {
                st.push('(');
                break;
            }
            st.pop();            
        }
    }

    return st.size() == 0;
}
