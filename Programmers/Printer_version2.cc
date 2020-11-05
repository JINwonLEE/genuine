#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct item {
    int index;
    int pri;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<item> q;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
    }
    sort(priorities.begin(), priorities.end(), greater<int>());
    int max_pri_index = 0;
    int count = 1;
    while (!q.empty()) {
        item cur = q.front();
        q.pop();
        if (cur.pri == priorities[max_pri_index]) {
            if (cur.index == location) break;
            count++;
            max_pri_index++;
        } else {
            q.push(cur);
        }
    }
    
    return count;
}

