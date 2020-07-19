class Solution {
public:
    map<int, vector<int>> edges;
    vector<bool> visit;
    vector<int> result;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto pre : prerequisites) edges[pre[0]].push_back(pre[1]);
        visit = vector<bool>(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visit[i]) {
                if (!dfs(i)) return {};
            }
        }
        
        return result;
    }
    
    bool dfs(int pos) {
        if (visit[pos]) {
            return false;
        }
        
        visit[pos] = true;
        bool res = true;
        if (edges.find(pos) == edges.end()) {
            result.push_back(pos);
            return res;
        } else {
            for (auto edge : edges[pos]) {
                if (find(result.begin(), result.end(), edge) == result.end()) {
                    res = res && dfs(edge);
                }
            }
            result.push_back(pos);
        }
        
        return res;
    }
};
