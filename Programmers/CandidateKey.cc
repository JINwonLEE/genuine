#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<string>> rel;
set<vector<int>> pos;
int answer;

void makeGet(int index, int C, vector<int> k, vector<vector<int>>& get) {
    if (k.size() == C) {
        bool isValid = true;
        for (auto ele : pos) {
            if (includes(k.begin(), k.end(), ele.begin(), ele.end())) {
                isValid = false;
                break;
            }
        }
        if (isValid) get.push_back(k);
        return;
    }
    for (; index < rel[0].size(); index++) {
        k.push_back(index);
        makeGet(index + 1, C, k, get);
        k.pop_back();
    }
}

void find(int k) {
    vector<vector<int>> get;
    vector<int> kind;
    makeGet(0, k, kind, get);
    for (int i = 0; i < get.size(); i++) {
        set<vector<string>> check_set;
        for (int j = 0; j < rel.size(); j++) {
            vector<string> tmp;
            for (int k = 0; k < get[i].size(); k++) {
                tmp.push_back(rel[j][get[i][k]]);
            }
            check_set.insert(tmp);
        }
        if (check_set.size() == rel.size()) {
            vector<int> tmp;
            for (int m = 0; m < get[i].size(); m++) {
                tmp.push_back(get[i][m]);
            }
            pos.insert(tmp);
            answer++;
        }
    }
}

int solution(vector<vector<string>> relation) {
    rel = relation;
    for (int i =  1; i <= rel[0].size(); i++) {
        find(i);
    }
    
    return answer;
}
