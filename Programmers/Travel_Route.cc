#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool getRoute(string start, vector<vector<string>>& tickets, vector<string>& result) {
    vector<string> possible;
    map<string, int> t_to_ind;
    result.push_back(start);
    if (result.size() == tickets.size() + 1) return true;
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == start) {
            possible.push_back(tickets[i][1]);
            t_to_ind[tickets[i][1]] = i;
        }
    }
    sort(possible.begin(), possible.end());
    for (int i = 0; i < possible.size(); i++) {
        string tmp = tickets[t_to_ind[possible[i]]][0];
        tickets[t_to_ind[possible[i]]][0] = "-";
        if (getRoute(possible[i], tickets, result)) return true;
        tickets[t_to_ind[possible[i]]][0] = tmp;
    }
    
    result.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visit(tickets.size(), false);
    getRoute("ICN", tickets, answer);
    return answer;
}
