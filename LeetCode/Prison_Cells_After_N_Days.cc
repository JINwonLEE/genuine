class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        N = N % 14 == 0 ? 14 : N % 14;
        
        vector<int> temp;
        for (int i = 0 ; i < N; i++) {
            temp = cells;
            cells[0] = 0;
            cells[7] = 0;
            for (int j = 1; j < 7; j++) {
                cells[j] = (temp[j-1]^temp[j+1])^0x1;
            }
        }
        
        return cells;
    }
};
