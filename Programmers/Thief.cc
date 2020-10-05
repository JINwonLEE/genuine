#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int *dp = new int[money.size() - 1];
    int *dp2 = new int[money.size()];
    dp[0] = money[0];
    dp[1] = money[0];
    
    for (int i = 2; i < money.size() - 1; i++) {
        dp[i] = max(dp[i-2] + money[i], dp[i-1]);
    }
    
    dp2[0] = 0;
    dp2[1] = money[1];
    for (int i = 2; i < money.size(); i++) {
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    
    
    return max(dp2[money.size() - 1], dp[money.size() - 2]);
}
