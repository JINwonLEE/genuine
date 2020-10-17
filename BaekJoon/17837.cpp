#include <iostream>
#include <stack>
#include <vector>

using namespace std;
void moveIndex(int ind);
void mapFunction(int ind, int start_index); 

struct Item {
    int x, y;
    int d;
};

int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // right, left, up, down
int N, K, m[12][12];
int m_index[144];
int m_info[144][10];
int turn = 0;
Item mo[10];

bool isFour() {
    for (int i = 0; i < N*N; i++) {
        if (m_index[i] >= 4) return true;
    }
    return false;
}

int calIndex(int x, int y) {
    return x*N + y;
}

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < N*N; i++) {
        for (int j = 0; j < K; j++) {
            m_info[i][j] = -1; // No item 
        }
        m_index[i] = 0;
    }

    for (int i = 0; i < K; i++) {
        cin >> mo[i].x >> mo[i].y >> mo[i].d;
        mo[i].x--;
        mo[i].y--;
        mo[i].d--;
        int info_index = calIndex(mo[i].x, mo[i].y);
        m_info[info_index][m_index[info_index]++] = i;
    }
}

int getStartIndex(int index) {
    int x = mo[index].x;
    int y = mo[index].y;
    int cal_ind = calIndex(x, y);
    int top_ind = m_index[cal_ind];
    for (int i = top_ind; i >= 0; i--) {
        if (m_info[cal_ind][i] == index) {
            return i;
        }
    }
    return 0;
}

bool isValid(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}

vector<int> removeFromIndex(int ind) {
    int m_ind = calIndex(mo[ind].x, mo[ind].y);
    int start_index = getStartIndex(ind); 
    int end_index = m_index[m_ind];
    vector<int> orders;
    for (int i = start_index; i < end_index; i++) {
        int mo_index = m_info[m_ind][i];
        orders.push_back(mo_index);
        m_info[m_ind][i] = -1;
    }
    m_index[m_ind] = start_index;
    return orders;
}

int moveByIndexDir(int ind, vector<int>& orders) {
    int dir = mo[ind].d;
    int new_start_index = -1;
    for (int i = 0 ; i < orders.size(); i++) {
        mo[orders[i]].x += direction[dir][0]; 
        mo[orders[i]].y += direction[dir][1]; 
        int new_m_ind = calIndex(mo[orders[i]].x, mo[orders[i]].y);
        if (new_start_index == -1) 
            new_start_index = m_index[new_m_ind];
        m_info[new_m_ind][m_index[new_m_ind]++] = orders[i];
    }
    return new_start_index;
}

void mapFunctionInvalidMove(int ind) {
    if (mo[ind].d == 0) mo[ind].d = 1;
    else if (mo[ind].d == 1) mo[ind].d = 0;
    else if (mo[ind].d == 2) mo[ind].d = 3;
    else mo[ind].d = 2;

    int dir = mo[ind].d;
    if (isValid(mo[ind].x + direction[dir][0], mo[ind].y + direction[dir][1])
            && m[mo[ind].x + direction[dir][0]][mo[ind].y + direction[dir][1]] != 2) {
        vector<int> orders = removeFromIndex(ind);
        int new_start_index = moveByIndexDir(ind, orders);
        mapFunction(ind, new_start_index);
    }
}

void mapFunction(int ind, int start_index) {
    int x = mo[ind].x;
    int y = mo[ind].y;
    int type = m[x][y];
    int m_ind = calIndex(x, y);

    if (type == 1) { // Red
        // Reverse order
        stack<int> tmp;
        for (int i = start_index; i < m_index[m_ind]; i++) {
            tmp.push(m_info[m_ind][i]);
        }

        for (int i = start_index; i < m_index[m_ind]; i++) {
            int ele = tmp.top(); tmp.pop();
            m_info[m_ind][i] = ele;
        }
    } else if (type == 2) { // Blue
        if (mo[ind].d == 0) mo[ind].d = 1;
        else if (mo[ind].d == 1) mo[ind].d = 0;
        else if (mo[ind].d == 2) mo[ind].d = 3;
        else mo[ind].d = 2;
        vector<int> orders = removeFromIndex(ind);
        moveByIndexDir(ind, orders);

        int dir = mo[ind].d;
        int tmp_x = mo[ind].x + direction[dir][0];
        int tmp_y = mo[ind].y + direction[dir][1];

        if (isValid(tmp_x, tmp_y) && m[tmp_x][tmp_y] != 2) {
            moveIndex(ind);
        }
    }
}

void moveIndex(int ind) {
    int m_ind = calIndex(mo[ind].x, mo[ind].y);
    int dir = mo[ind].d;
    int new_start_index = -1;
    vector<int> orders = removeFromIndex(ind);
    if (isValid(mo[orders[0]].x + direction[dir][0], mo[orders[0]].y + direction[dir][1])) {
        new_start_index = moveByIndexDir(ind, orders);
        mapFunction(ind, new_start_index);
    } else {
        for (auto ele : orders) {
            m_info[m_ind][m_index[m_ind]++] = ele;
        }
        mapFunctionInvalidMove(ind);
    }
}

int main() {
    input();
    while (turn <= 1000 && !isFour()) {
        for (int i = 0; i < K; i++) {
            moveIndex(i);
            if (isFour()) break;
        }
        turn++;
    }

    if (turn > 1000) turn = -1;
    cout << turn << endl;
    return 0;
}
