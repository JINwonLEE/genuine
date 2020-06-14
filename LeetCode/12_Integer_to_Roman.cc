class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        int remain = num;
        
        for (int i = 0; i < remain / 1000; i++) {
            roman += "M";
        }
        
        remain = remain % 1000;
        
        if (remain / 100 == 9) {
            roman += "CM";
        } else if (remain / 100 >= 5) {
            roman += "D";
            for (int i = 0;  i < remain / 100 - 5; i++) {
                roman += "C";
            }
        } else if (remain / 100 == 4) {
            roman += "CD";
        } else {
            for (int i = 0; i < remain / 100; i++) {
                roman += "C";
            }
        }
        
        remain = remain % 100;
        
        if (remain / 10 == 9) {
            roman += "XC";
        } else if (remain / 10 >= 5) {
            roman += "L";
            for (int i = 0;  i < remain / 10 - 5; i++) {
                roman += "X";
            }
        } else if (remain / 10 == 4) {
            roman += "XL";
        } else {
            for (int i = 0; i < remain / 10; i++) {
                roman += "X";
            }
        }
        
        remain = remain % 10;
        if (remain == 9) {
            roman += "IX";
        } else if (remain >= 5) {
            roman += "V";
            for (int i = 0;  i < remain - 5; i++) {
                roman += "I";
            }
        } else if (remain == 4) {
            roman += "IV";
        } else {
            for (int i = 0; i < remain; i++) {
                roman += "I";
            }
        }
        
        return roman;
    }
};
