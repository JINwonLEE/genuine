class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int current = digits.size() - 1;
        while (current >= 0) {
            digits[current]++;
            if (digits[current] > 9) {
                digits[current] -= 10;
                current--;
                if (current < 0) {
                    digits.insert(digits.begin(), 1);
                    break;
                }
            } else {
                break;
            }
        }
        return digits;
    }
};
