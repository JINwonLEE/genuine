#include <string>
#include <vector>

using namespace std;

string toBinary(int a) {
    string res = "";
    while (a > 0) {
        if (a % 2 == 0) {
            res = res + "0";
        } else {
            res = res + "1";
        }
        a /= 2;
    }
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    string tmp = s;
    int count = 0;
    int case_count = 0;
    while (tmp != "1") {
        string t = "";
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] == '1') {
                t += "1";
            } else {
                count++;
            }
        }
        tmp = toBinary(t.size());
        case_count++;
    }
    answer.push_back(case_count);
    answer.push_back(count);
    return answer;
}
