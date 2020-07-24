class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> list;
        findPath(0, list, graph, result);
        return result;
    }
    
    void findPath(int pos, vector<int>& list, vector<vector<int>>& graph, vector<vector<int>>& result) {
        list.push_back(pos);
        if (pos == graph.size() - 1) result.push_back(list);
        
        for (int i = 0; i < graph[pos].size(); i++) {
            findPath(graph[pos][i], list, graph, result);
        }
        list.pop_back();
        return;
    }
};
