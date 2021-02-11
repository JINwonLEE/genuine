#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> ord;

void getCand(string str, int ind, string tmp, int len, vector<string>& res) {
    if (len == tmp.size()) {
        res.push_back(tmp);
        return;
    }
    for (; ind < str.size(); ind++) {
        tmp += str[ind];  
        getCand(str, ind + 1, tmp, len, res);
        tmp = tmp.substr(0, tmp.size() - 1); 
    }
}

vector<string> getCandidate(string str, int len) {
    vector<string> result;
    string tmp = "";
    getCand(str, 0, tmp, len, result);
    
    return result;
}

bool findCandidate(string str, string sub) {
    for (int i = 0; i < sub.size(); i++) {
        bool isValid = false;
        for (int j = 0; j < str.size(); j++) {
            if (sub[i] == str[j]) {
                isValid = true;
                break;
            }
        }
        if (!isValid) return false;
    }
    
    return true;
}

void getResult(int len, vector<string>& ans) {
    int max_count = 1;
    vector<string> tmp_result;
    for (int i = 0 ; i < ord.size(); i++) {
        vector<string> candidate;
        candidate = getCandidate(ord[i], len);
        for (auto cand : candidate) {
            int count = 1;
            for (int j = i + 1; j < ord.size(); j++) {
                string tmp = ord[j];
                if (findCandidate(tmp, cand)) {
                    count++;
                }
            }
            
            if (count == 1) continue;
            if (max_count < count) {
                max_count = count;
                tmp_result.clear();
                tmp_result.push_back(cand);
            } else if (max_count == count) {
                tmp_result.push_back(cand);
            }
        }
    }
    for (auto ele : tmp_result) {
        sort(ele.begin(), ele.end());
        ans.push_back(ele);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    ord = orders;
    
    for (int i = course.size() - 1; i >= 0; i--) {
        getResult(course[i], answer);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
