#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

struct res {
    string uid;
    bool enter;
};

map<string, string> uid_to_nickname;
vector<res> results;

void investigate(string str) {
    stringstream s(str);
    string tmp;
    vector<string> tokens;
    while (getline(s, tmp, ' ')) {
        tokens.push_back(tmp);
    }
    
    if (tokens[0] == "Enter") {
        uid_to_nickname[tokens[1]] = tokens[2];
        results.push_back({tokens[1], true});
    } else if (tokens[0] == "Leave") {
        results.push_back({tokens[1], false});
    } else {
        uid_to_nickname[tokens[1]] = tokens[2];
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (auto ele : record) {
        investigate(ele);
    }
    
    for (auto ele : results) {
        string tmp = "";
        tmp += uid_to_nickname[ele.uid];
        if (ele.enter) {
            tmp += "님이 들어왔습니다.";
        } else {
            tmp += "님이 나갔습니다.";
        }
        answer.push_back(tmp);
    }
    return answer;
}
