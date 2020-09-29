#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    
    for (int i = 0; i < puddles.size(); i++) {
        dp[puddles[i][1]-1][puddles[i][0]-1] = -1;
    }
    
    dp[0][0] = 1;
    for (int i = 1; i < m; i++) {
        if (dp[0][i] != -1) dp[0][i] = 1;
        else break;
    }
    
    for (int i = 1; i < n; i++) {
        if (dp[i][0] != -1) dp[i][0] = 1;
        else break;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] == -1) continue;
            if (dp[i-1][j] != -1) dp[i][j] += dp[i-1][j] % 1000000007;
            if (dp[i][j-1] != -1) dp[i][j] += dp[i][j-1] % 1000000007;
        }
    }
    
    return dp[n-1][m-1] % 1000000007;
}
