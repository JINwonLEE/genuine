class Solution {
public:
    map<int, int> start_to_cost;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        std::ios::sync_with_stdio(false);cin.tie(nullptr);
        return minCost(days, costs, 0);
    }
    
    int minCost(vector<int>& days, vector<int>& costs, int start_index) {
        if (start_to_cost.find(start_index) != start_to_cost.end()) return start_to_cost[start_index];
        if (start_index >= days.size()) return 0;

        int start_day = days[start_index];
        int one_day = start_index + 1;
        int seven_day = start_index + 1;
        int thirty_day = start_index + 1;
        for (int i = start_index + 1; i < days.size(); i++) {
            if (days[i] <= start_day + 6) seven_day++;
            if (days[i] <= start_day + 29) thirty_day++;
        }
        start_to_cost[start_index] = min(minCost(days, costs, one_day) + costs[0], 
                                         min(minCost(days, costs, seven_day) + costs[1], 
                                            minCost(days, costs, thirty_day) + costs[2]));

        return start_to_cost[start_index];
    }
};
