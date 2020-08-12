class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        if (rowIndex == 0 || rowIndex == 1) return result;
        vector<int> temp(rowIndex - 1, 0);
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = 1; j < i; j++) temp[j - 1] = result[j - 1] + result[j];
            for (int j = 0; j < i - 1; j++) result[j + 1] = temp[j]; 
        }
        return result;
    }
};
