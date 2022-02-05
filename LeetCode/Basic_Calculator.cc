class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int ret = 0;
        long int cur_value = 0;
        int sign = 1;
        for (int i = 0; i < s.size(); i++) {
            while (s[i] >= '0' && s[i] <= '9') {
                cur_value = cur_value * 10 + s[i] - '0';
                i++;
            } 
            ret += (sign * cur_value);
            cur_value = 0;
            if (s[i] == ')') {
                ret = ret * st.top();
                st.pop();
                ret += st.top();
                st.pop();   
            } else if (s[i] == '(') {
                st.push(ret);
                ret = 0;
                st.push(sign);
                sign = 1;
            } else if (s[i] == '+' || s[i] == '-') {
                sign = s[i] == '+' ? 1 : -1;
            }
        }
        return ret;
    }
};
