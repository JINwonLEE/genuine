class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 || n == 0) {
            return 1;
        }
        
        double result = myPow(x, n/2);
        
        if (n % 2) {
            result = n < 0 ? result * result * 1/x : result * result * x; 
        } else {
            result = result * result;
        }
        
        return result;
    }
};
