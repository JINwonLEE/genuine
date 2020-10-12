#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

long long maximum = LLONG_MIN;
long long minimum = LLONG_MAX;
int N;

void findNum(const vector<int>& num, int num_oper[4], int index, int sum) {
    for (int i = 0; i < 4; i++) {
        if (num_oper[i] != 0) {
            int tmp_sum = sum;
            if (i == 0) {
                tmp_sum += num[index];
            } else if (i == 1) {
                tmp_sum -= num[index];
            } else if (i == 2) {
                tmp_sum *= num[index];
            } else {
                tmp_sum /= num[index];
            }
            if (index == N - 1) {
                if (tmp_sum < minimum) minimum = tmp_sum;
                if (tmp_sum > maximum) maximum = tmp_sum;
                return;
            } else {
                num_oper[i]--;
                findNum(num, num_oper, index + 1, tmp_sum);
                num_oper[i]++;
            }
        }
    }
}

int main() {
    int num_oper[4];
    cin >> N;
    vector<int> num(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> num_oper[i];
    }

    findNum(num, num_oper, 1, num[0]);
    cout << maximum << endl;
    cout << minimum << endl;

	return 0;
}
