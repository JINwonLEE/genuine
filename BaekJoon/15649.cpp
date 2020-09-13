#include <iostream>
#include <vector>

using namespace std;

void getPermutation(bool* visit, int N, int M, vector<int>& tmp,
                    vector<vector<int>>& result) {
    if (M == 0) {
        result.push_back(tmp);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            tmp.push_back(i+1);
            visit[i] = true;
            getPermutation(visit, N, M - 1, tmp, result);
            visit[i] = false;
            tmp.pop_back();
        }
    }
}

int main() {
    int N, M;
    vector<vector<int>> answer;

    cin >> N >> M;
    bool* visit = new bool[N];
    for (int i = 0; i < N; i++) visit[i] = false;

    vector<int> tmp;
    getPermutation(visit, N, M, tmp, answer);

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < M; j++) {
            cout << answer[i][j];
            if (j != M - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}


