class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        
        for (int i = 0; i <= K; i++) {
            vector<int> temp(cost);
            for (int j = 0; j < flights.size(); j++) {
                int source = flights[j][0];
                int destination = flights[j][1];
                int price = flights[j][2];
                
                if (temp[source] == INT_MAX) {
                    continue;
                }
                
                if (cost[destination] > temp[source] + price) {
                    cost[destination] = temp[source] + price;
                }
            }
        }
        
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
