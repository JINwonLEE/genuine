#include <string>
#include <vector>
#include <string>

using namespace std;

char op[6][3] = {
    {'+', '-', '*'},
    {'+', '*', '-'},
    {'-', '+', '*'},
    {'-', '*', '+'},
    {'*', '-', '+'},
    {'*', '+', '-'},
};

long long getNum(int ind, int ord, vector<string> tokens) {
    char oper = op[ind][ord];
    int index = 0;
    
    while (index < tokens.size()) {
        if (tokens[index][0] == oper) {
            long long left = stoll(tokens[index-1]);
            long long right = stoll(tokens[index+1]);
            long long result = 0;
            if (oper == '*') result = left * right;
            if (oper == '+') result = left + right;
            if (oper == '-') result = left - right;
            tokens[index - 1] = to_string(result);
            for (int i = index; i < tokens.size()-2; i++) {
                tokens[i] = tokens[i+2];
            }
            index--;
            tokens.resize(tokens.size() - 2);
        }
        index++;
    }
    
    if (ord == 2) return stoll(tokens[0]) > 0 ? stoll(tokens[0]) : -1 * stoll(tokens[0]);
    return getNum(ind, ord + 1, tokens);
}

vector<string> makeToken(string expr) {
    int index = 0;
    vector<string> tokens;
    string tmp = "";
    bool isNum = true;
    while (index < expr.size()) {
        if (expr[index] == '*' || expr[index] == '+' || expr[index] == '-') {
            tokens.push_back(tmp);
            isNum = false;
            tmp = expr[index];
        } else {
            if (!isNum) {
                tokens.push_back(tmp);
                tmp = expr[index];
                isNum = true;
            } else {
                tmp += expr[index];
            }
        }
        index++;
    }
    if (tmp != "") {
        tokens.push_back(tmp);
    }
    return tokens;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<string> tokens = makeToken(expression);
    for (int i = 0; i < 6; i++) {
        long long tmp = getNum(i, 0, tokens);
        answer = max(answer, tmp);
    }
    return answer;
}
