#include <string>
#include <vector>
#include <set>

using namespace std;

bool isPrime(int num) {
    if (num == 1 || num == 0) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }    
    }
    return true;
}

set<int> list;

void getPrimeNum(vector<string>& v, int length, string num) {
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "-" || (num == "" && v[i] == "0")) continue;
        num += v[i];
        string tmp = v[i];
        v[i] = "-";
        if (length == num.size()) {
            if (isPrime(stoi(num))) {
                list.insert(stoi(num));   
            }
        } else {
            getPrimeNum(v, length, num);
        }
        v[i] = tmp;
        num.erase(num.end() - 1);
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<string> v;
    for (int i  = 0; i < numbers.size(); i++) {
        string tmp = "";
        tmp += numbers[i];
        v.push_back(tmp);
    }
    for (int i = 1; i <= numbers.size(); i++) {
        getPrimeNum(v, i, "");   
    }
    return list.size();
}
