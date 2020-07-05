class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming = x^y;
        int count = 0;
        for (; hamming > 0; hamming = hamming >> 1) {
            if (hamming & 0x1 == 1) {
                count++;
            }
        }
        return count;
    }
};
