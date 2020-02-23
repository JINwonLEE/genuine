#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        int s_size = s.length();
        int p_size = p.length();

        bool **result = new bool *[s_size + 1];
        for (int i = 0; i <= s_size; i++) {
            result[i] = new bool[p_size + 1];
            for (int j = 0; j <= p_size; j++) {
                result[i][j] = false;
            }
        }
        result[0][0] = true;

        if (p_size >= 2 && p[1] == '*') {
            result[0][2] = true;
        }

        for (int i = 2; i < p_size; i++) {
            if (p[i] == '*') {
                result[0][i + 1] = result[0][i - 1];
            }
        }

        for (int i = 1; i <= s_size; i++) {
            for (int j = 1; j <= p_size; j++) {
                if (p[j - 1] == '*') {
                    if (p[j - 2] != s[i - 1] && p[j - 2] != '.') {
                        result[i][j] = result[i][j - 2];
                    } else {
                        result[i][j] = result[i - 1][j - 2] ||
                                       result[i][j - 2] || result[i - 1][j];
                    }
                } else {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                        result[i][j] = result[i - 1][j - 1];
                    }
                }
            }
        }

        return result[s_size][p_size];
    }
};

int main() {
    Solution *a = new Solution();

    cout << (a->isMatch("aab", "c*a*b") == 1) << endl;
    cout << (a->isMatch("aa", "a") == 0) << endl;
    cout << (a->isMatch("aa", "a*") == 1) << endl;
    cout << (a->isMatch("ab", ".*") == 1) << endl;
    cout << (a->isMatch("mississippi", "mis*is*p*.") == 0) << endl;
    cout << (a->isMatch("ab", ".*c") == 0) << endl;
    cout << (a->isMatch("ab", ".*c*") == 1) << endl;
    cout << (a->isMatch("aaa", "a*a") == 1) << endl;
    cout << (a->isMatch("aaa", "a*c*a") == 1) << endl;
    return 0;
}
