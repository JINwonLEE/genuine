class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
        int* buy1;
        int* buy2;
        int* sell1;
        int* sell2;
        int len = prices.size();
        buy1 = new int[len];
        buy2 = new int[len];
        sell1 = new int[len];
        sell2 = new int[len];
        
        if (prices.size() <= 1) return 0;
        if (prices.size() == 2) return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        if (prices.size() == 3) return max(0, max(prices[2] - prices[1], 
                                        max(prices[1] - prices[0], prices[2] - prices[0])));
        
        buy1[0] = -1 * prices[0];
        buy2[0] = 0;
        sell1[0] = 0;
        sell2[0] = 0;
        
        buy1[1] = max(-1 * prices[0], -1 * prices[1]);
        buy2[1] = 0;
        sell1[1] = buy1[0] + prices[1];
        sell2[1] = 0;
        
        buy1[2] = max(-1 * prices[2], buy1[1]);
        buy2[2] = -1 * prices[0] + prices[1] + prices[2] * -1;
        sell1[2] = max(sell1[1], buy1[1] + prices[2]);
        sell2[2] = 0;
        
        buy1[3] = max(-1 * prices[3], buy1[2]);
        buy2[3] = max(buy2[2], sell1[2] - prices[3]);
        sell1[3] = max(sell1[2], buy1[2] + prices[3]);
        sell2[3] = buy2[2] + prices[3];
        
        for (int i = 4; i < len; i++) {
            buy1[i] = max(-1 * prices[i], buy1[i-1]);
            buy2[i] = max(buy2[i-1], sell1[i-1] - prices[i]);
            sell1[i] = max(sell1[i-1], buy1[i-1] + prices[i]);
            sell2[i] = max(sell2[i-1], buy2[i-1] + prices[i]);
        }
        
        return max(0, max(sell1[len-1], sell2[len-1]));     
    }
};
