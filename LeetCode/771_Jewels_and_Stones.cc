class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool alphabet[52];
        for (int i = 0; i < 52; i++) {
            alphabet[i] = false;
        }
        
        for (int i = 0; i < J.length(); i++) {
            int index = (J[i] - 'A' > 25) ? J[i] - 'a' + 26 : J[i] - 'A'; 
            alphabet[index] = true;
        }
        
        int count = 0;
        for (int i = 0; i < S.length(); i++) {
            int index = (S[i] - 'A' > 25) ? S[i] - 'a' + 26 : S[i] - 'A';
            if (alphabet[index]) {
                count++;
            }
        }
        return count;
    }
};
