#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int* parent = new int[n];
    for (int i = 0; i < n; i++) parent[i] = i;
    sort(costs.begin(), costs.end(), compare);
    
    int answer = 0;
    for (int i = 0; i < costs.size(); i++) {
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];
        
        if (parent[start] != parent[end]) {
            if (start < end) {
                int tmp = parent[end];
                for (int j = 0; j < n; j++) {
                    if (tmp == parent[j]) {
                        parent[j] = parent[start];
                    }
                }
            } else {
                int tmp = parent[start];
                for (int j = 0; j < n; j++) {
                    if (tmp == parent[j]) {
                        parent[j] = parent[end];
                    }
                }
            }
            answer += cost;
        }
    }
    
    return answer;
}
