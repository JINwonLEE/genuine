#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct item {
    int t;
    int remain;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> trucks;
    for (auto t : truck_weights) {
        trucks.push(t);
    }
    
    vector<item> on_bridge;
    int remain = weight;
    int count = 0;
    while (!trucks.empty()) {
        count++;
        for (int i = 0; i < on_bridge.size(); i++) {
            if (on_bridge[i].remain == 0) {
                remain += on_bridge[i].t;
            }
        }
        int cur = trucks.front();
        if (remain >= cur) {
            remain -= cur;
            trucks.pop();
            on_bridge.push_back({cur, bridge_length});
        }

        for (int i = 0; i < on_bridge.size(); i++) {
            on_bridge[i].remain--;
        }
    }
    
    while (true) {
        bool isDone = true;
        for (int i = 0; i < on_bridge.size(); i++) {
            if (on_bridge[i].remain >= 0) {
                isDone = false;
                on_bridge[i].remain--;
            }
        }
        if (isDone) break;
        count++;
    }
    
    return count;
}
