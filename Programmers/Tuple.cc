#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    s = s.substr(1, s.size() - 2);
    int index = 0;
    bool isOpen = false;
    string tmp = "";
    vector<vector<int>> bucket;
    vector<int> list;
    while (index < s.size()) {
        if (s[index] == '{') {
            tmp = "";
            list.clear();
            isOpen = true;
            index++;
            continue;
        } else if (s[index] == '}') {
            isOpen = false;
            index++;
            stringstream ss(tmp);
            string tok;
            while (getline(ss, tok, ',')) {
                list.push_back(stoi(tok));
            }
            bucket.push_back(list);
            continue;
        } else {
            tmp += s[index++];
        }
    }
    sort(bucket.begin(), bucket.end(), comp);
    for (int i = 0; i < bucket.size(); i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            if (find(answer.begin(), answer.end(), bucket[i][j]) 
                == answer.end()) {
                answer.push_back(bucket[i][j]);
            }
        }
    }
    return answer;
}
