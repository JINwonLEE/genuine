class Solution {
public:
    int climbStairs(int n) {
        int* count = new int[n];
        count[0] = 1;
        if (n >=2) {
            count[1] = 2;
            for (int i = 2; i < n; i++) {
                count[i] = count[i-1] + count[i-2];
            } 
        }
        
        return count[n-1];
    }
};
