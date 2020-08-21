class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int front = 0;
        int end = A.size() - 1;
        while (front < end) {
            if (A[front] % 2 == 0) {
                front++;
                continue;
            }
            int tmp = A[end];
            A[end--] = A[front];
            A[front] = tmp;
        }
        return A;
    }
};
