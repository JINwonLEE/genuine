class Solution {
public:
    string toGoatLatin(string S) {
        string result = "";
        stringstream check(S);
        string intermediate;
        string dummy = "a";
        while (getline(check, intermediate, ' ')) {
            char first = tolower(intermediate[0]);
            if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') {
                intermediate += "ma";
            } else {
                intermediate = intermediate.substr(1) + intermediate[0] + "ma";
            }
            intermediate += dummy;
            dummy += "a";
            result += intermediate + " ";
        }
        return result.substr(0, result.size() - 1);
    }
};
