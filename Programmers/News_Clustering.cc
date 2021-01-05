#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> list_1;
vector<string> list_2;

bool isValid(string str) {
    char v1 = str[0];
    char v2 = str[1];
    
    if (!(v1 >= 'a' && v1 <='z') && !(v1 >= 'A' && v1 <= 'Z')) {
        return false;
    }
    if (!(v2 >= 'a' && v2 <='z') && !(v2 >= 'A' && v2 <= 'Z')) {
        return false;
    }
    
    return true;
}

void makeList(string str, bool isOne) {
    for (int i = 0; i < str.size() - 1; i++) {
        string tmp = "";
        tmp += str[i];
        tmp += str[i+1];
        if (isValid(tmp)) {
            transform(tmp.cbegin(), tmp.cend(), tmp.begin(), ::tolower);
            if (isOne) {
                list_1.push_back(tmp);
            } else {
                list_2.push_back(tmp);
            }
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    int common = 0;
    int total = 0;
    
    makeList(str1, true);
    makeList(str2, false);
    for (int i = 0; i < list_1.size(); i++) {
        for (int j = 0; j < list_2.size(); j++) {
            if (list_1[i] == list_2[j]) {
                common++;
                list_2.erase(list_2.begin() + j);
                break;
            }
        }
        total++;
    }
    total += list_2.size();
    if (total== 0) answer = 65536;
    else {
        double tmp = double(common) / double(total) * 65536;
        answer = tmp;
    }
    return answer;
}
