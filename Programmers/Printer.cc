#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> index_list;
    queue<int> q;
    int max_pri = 0;
    bool* print = new bool[priorities.size()];
    for (int i = 0; i < priorities.size(); i++) {
        print[i] = false;
        q.push(i);
        if (max_pri < priorities[i]) max_pri = priorities[i];
    }
    
    while (!q.empty()) {
        int cur = q.front();
        if (priorities[cur] < max_pri) {
            q.pop();
            q.push(cur);
        } else {
            index_list.push_back(cur);
            q.pop();
            print[cur] = true;
            int tmp = 0;
            for (int i = 0; i < priorities.size(); i++) {
                if (!print[i] && tmp < priorities[i]) {
                    tmp = priorities[i];
                }
            }
            max_pri = tmp;
        }
    }
    
    for (int i = 0; i < index_list.size(); i++) {
        if (index_list[i] == location) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}
