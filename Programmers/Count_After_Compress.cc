#include <string>
#include <vector>

using namespace std;
vector<vector<int>> map;

void dfs(int x, int y, int size, vector<int>& answer) {
    bool oneValid = true;
    bool zeroValid = true;
    if (size == 0) return;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (map[i][j] == 0) oneValid = false;
            if (map[i][j] == 1) zeroValid = false;
        }
    }
    
    if (oneValid) {
        answer[1]++;
        return;
    }
    
    if (zeroValid) {
        answer[0]++;
        return;
    }
    dfs(x, y, size / 2, answer);
    dfs(x, y + size / 2, size / 2, answer);
    dfs(x + size / 2, y, size / 2, answer);
    dfs(x + size / 2, y + size / 2, size / 2, answer);
    
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    map = arr;
    dfs(0, 0, arr.size(), answer);
    
    return answer;
}
