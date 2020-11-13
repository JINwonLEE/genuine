#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string p) {
    stack<char> st;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') st.push(p[i]);
        else  {
            if (st.empty()) return false;
            st.pop();
        }
    }
    
    if (st.size() != 0) return false;
    return true;
}

string getAnswer(string p) {
    string ret = "";
    if (p == "") return p;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') count1++;
        if (p[i] == ')') count2++;
        if (count1 != 0 && count2 != 0 && count1 == count2) break;
    }
    string u = p.substr(0, count1 * 2);
    string v = p.substr(count1 * 2);
    v = getAnswer(v);
    if (isValid(u)) {
        ret = u + v;
    } else {
        ret += "(";
        ret += v;
        ret += ")";
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') ret += ')';
            if (u[i] == ')') ret += '(';
        }
    }
    return ret;
}


string solution(string p) {
    string answer = "";
    answer = getAnswer(p);
    return answer;
}
