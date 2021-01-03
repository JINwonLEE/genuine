#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, bool> check;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    char prev = '-';
    for (int i = 0; i < words.size(); i++) {
        if (prev == '-') {
            prev = words[i][0];
        }
        if (check[words[i]] || prev != words[i][0]) {
            answer.push_back((i % n) + 1);
            answer.push_back(i / n + 1);
            break;
        } else {
            check[words[i]] = true;
        }
        prev = words[i][words[i].size() - 1];
    }
    if (answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}
