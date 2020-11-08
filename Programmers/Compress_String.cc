#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int length = s.length();
    for (int i = 1; i <= s.length() / 2; i++) {
        string sub = s.substr(0, i);
        int count = 1;
        string sample = "";
        for (int j = i; j < s.length(); j += i) {
            string cmp = s.substr(j, i);
            if (sub == cmp) {
                count++;
            } else {
                if (count == 1) {
                    sample = sample + sub;
                } else {
                    sample = sample + to_string(count) + sub;
                }
                sub = cmp;
                count = 1;
            }
            
            if (j + i >= s.length()) {
                if (count == 1) {
                    sample = sample + s.substr(j);
                } else {
                    sample = sample + to_string(count) + sub;    
                }
            }
        }
        if (sample.length() < length) {
            length = sample.length();
        }
    }
    
    return length;
}
