#include <iostream>
#include <vector>

using namespace std;

int dices[10];
vector<vector<int>> map_ = {{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40} 
                            ,{10, 13, 16, 19, 25, 30, 35, 40}, {20, 22, 24, 25, 30, 35, 40}, 
                            {30, 28, 27, 26, 25, 30, 35, 40}};
int maximum_score = 0;
bool print_log = false;

void input() {
    for (int i = 0; i < 10; i++)
        cin >> dices[i];
}

bool isValid(int i, int k, int** m_list) {
    int i_r = m_list[i][0];
    int i_h = m_list[i][1];
    int i_v = map_[i_r][i_h];
    int k_r = m_list[k][0];
    int k_h = m_list[k][1];
    int k_v = map_[k_r][k_h];

    if (i_v != k_v) return true;

    switch (i_v) {
        case 16:
            if (i_r != k_r) return true;
            break;
        case 22:
            if (i_r != k_r) return true;
            break;
        case 24:
            if (i_r != k_r) return true;
            break;
        case 26:
            if (i_r != k_r) return true;
            break;
        case 28:
            if (i_r != k_r) return true;
            break;
        case 30:
            if (i_r != k_r || (i_r == k_r && i_h != k_h)) return true;
            break;
    }

    return false;
    

}

int moveM(int m_num, int** m_list, int index) {
    int* m = m_list[m_num];
    int v = map_[m[0]][m[1]];
    if (m[0] == 0) {
        if (v == 10) {
            m[0] = 1;
            m[1] = dices[index];
        } else if (v == 20) {
            m[0] = 2;
            m[1] = dices[index];
        } else if (v == 30) {
            m[0] = 3;
            m[1] = dices[index];
        } else {
            m[1] += dices[index];
        }
    } else {
        m[1] += dices[index];
    }

    if (map_[m[0]].size() <= m[1]) {
        m[0] = -1;
        m[1] = -1;
        return 0;        
    }

    for (int i = 0; i < 4; i++) {
        if (i != m_num && m_list[i][0] != -1 && m_list[i][1] != -1) {
            if (!isValid(m_num, i, m_list)) {
                return -1;
            }
        }
    }    

    return map_[m[0]][m[1]];
}

void dfs(int** m, int score, int index) {
    if (index == 10) {
        if (maximum_score < score) {
            maximum_score = score;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (m[i][0] != -1 && m[i][1] != -1) {
            int x = m[i][0];
            int y = m[i][1];
            int tmp = moveM(i, m, index);
            if (tmp != -1) dfs(m, score + tmp, index + 1);
            m[i][0] = x;
            m[i][1] = y;
        }
    }
}

void solve() {
    int m[4][2];
    for (int i = 0 ; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            m[i][j] = 0;
        }
    }

    int* m_p[4];
    for (int i = 0 ;i < 4; i++) {
        m_p[i] = m[i];
    }
    dfs(m_p, 0, 0);    
}

int main() {
    input();
    solve();
    cout << maximum_score << endl;
}
