#include <string>
#include <vector>
#include <sstream>

using namespace std;

string getMax(string a, string b) {
    if (a[0] == '-' && b[0] == '-') {
        if (a.size() < b.size()) return a;
        if (a.size() > b.size()) return b;
        
        if (a > b) return b;
        return a;
    } 
    if (a[0] == '-') return b;
    if (b[0] == '-') return a;
    
    if (a.size() < b.size()) return b;
    if (a.size() > b.size()) return a;
    if (a > b) return a;
    return b;
}

string getMin(string a, string b) {
    if (a[0] == '-' && b[0] == '-') {
        if (a.size() < b.size()) return b;
        if (a.size() > b.size()) return a;
        
        if (a > b) return a;
        return b;
    } 
    if (a[0] == '-') return a;
    if (b[0] == '-') return b;
    
    if (a.size() < b.size()) return a;
    if (a.size() > b.size()) return b;
    if (a > b) return b;
    return a;
}

string solution(string s) {
    string answer = "";
    stringstream str(s);
    string tmp;
    vector<string> buck;
    while(getline(str, tmp, ' ')) {
        buck.push_back(tmp);
    }
    string max_ = buck[0];
    string min_ = buck[0];
    for (int i = 1; i < buck.size() ; i++) {
        max_ = getMax(max_, buck[i]);
        min_ = getMin(min_, buck[i]);
    }
    
    answer += min_ + " ";
    answer += max_;
    return answer;
}
