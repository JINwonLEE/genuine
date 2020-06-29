class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, 
            priority_queue<string, vector<string>, greater<string>>> from_to;
        for (auto ticket : tickets) {
            from_to[ticket[0]].push(ticket[1]);
        }
        
        vector<string> result;
        dfs("JFK", from_to, result);
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    void dfs(string current, 
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& from_to,
        vector<string>& result) {
        while (!from_to[current].empty()) {
            string destination = from_to[current].top();
            from_to[current].pop();
            dfs(destination, from_to, result);
        }
        
        result.push_back(current);
    }
};
