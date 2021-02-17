#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string getString(int n, int t, int m) {
    int num = 0;
    string ret = "";
    while (ret.size() < t * m) {
        int tmp = num;
        string tmp_string = "";
        if (tmp == 0) {
            ret += "0";
        }
        
        while (tmp != 0) {
            int remain = tmp % n;
            if (remain >= 10) {
                tmp_string += remain - 10 + 'A';
            } else {
                tmp_string += to_string(remain);
            }
            tmp /= n;
        }
        reverse(tmp_string.begin(), tmp_string.end());
        ret += tmp_string;
        num++;
    }
    return ret;
}

string getAnswer(string seq, int m, int p, int t) {
    p--;
    string ret = "";
    for (int i = 0; i < seq.size(); i++) {
        if (i % m == p) {
            ret += seq[i];
            if (ret.size() == t) {
                break;
            }
        }
    }
    return ret;
}


string solution(int n, int t, int m, int p) {
    string answer = "";
    string game_string = getString(n, t, m);
    answer = getAnswer(game_string, m, p, t);
    return answer;
}
