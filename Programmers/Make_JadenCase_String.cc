#include <string>
#include <vector>

using namespace std;

bool isAlphabet(char a) {
    if ((a - 'A' >= 0 && a - 'Z' <= 0) || (a - 'a' >= 0 && a - 'z' <= 0)) return true;
    return false;
}

string solution(string s) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (isAlphabet(s[i])) {
            if (i == 0 || s[i-1] == ' ') answer += toupper(s[i]);
            else answer += tolower(s[i]);
        } else {
            answer += s[i];
        }
    }
    return answer;
}
