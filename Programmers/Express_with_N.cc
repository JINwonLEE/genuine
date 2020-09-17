#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int getNum(int ind, vector<vector<int>>& v, int number) {
    if (ind > 9) return -1;
    for (int i = 1; i <= ind / 2; i++) {
        int j = ind - i;
        for (int i_num = 0; i_num < v[i].size(); i_num++) {
            for (int j_num = 0; j_num < v[j].size(); j_num++) {
                int numi = v[i][i_num];
                int numj = v[j][j_num];
                v[ind].push_back(numi + numj);
                v[ind].push_back(numi - numj);
                v[ind].push_back(numi * numj);
                if (numi != 0) v[ind].push_back(numj / numi);
                if (numj != 0) v[ind].push_back(numi / numj);
            }
        }
    }
    for (int i = 0; i < v[ind].size(); i++) {
        if (number == v[ind][i]) {
            return ind;
        }
    }
    return getNum(ind + 1, v, number);
}

int solution(int N, int number) {
    int answer = 0;
    vector<vector<int>> num(10);
    for (int i = 1; i < 10; i++) {
        int count = i-1;
        int tmp = N;
        while (count > 0) {
            tmp += N * pow(10, count--);
        }
        num[i].push_back(tmp);
    }
    answer = getNum(1, num, number);
    return answer;
}

int main() {
    int N, number;
    cin >> N >> number;
    cout << solution(N, number) << endl;
    return 0;
}
