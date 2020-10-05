#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    for (int i = 0; i < lost.size(); i++) {
        int lost_p = lost[i];
        auto check = find(reserve.begin(), reserve.end(), lost_p);
        if (check != reserve.end()) {
            reserve.erase(check);
            lost[i] = -1;
            continue;
        }
    }
    for (int i = 0; i < lost.size(); i++) {
        int lost_p = lost[i];
        if (lost_p == -1) continue;
        auto check = find(reserve.begin(), reserve.end(), lost_p-1);
        if (check != reserve.end()) {
            reserve.erase(check);
            continue;
        }
        check = find(reserve.begin(), reserve.end(), lost_p + 1);
        if (check != reserve.end()) {
            reserve.erase(check);
            continue;
        }
        answer--;
    }
    return answer;
}
