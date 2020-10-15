#include <iostream>
using namespace std;

struct Shark {
    int x, y;
    int c_dir;
    int priority[4][4];
};

struct Cell {
    int duration;
    int owner;
};

int direction_map[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // up, down, left, right
int N, M, k, count, times = 0;
int map_[20][20];
Cell s_map_[20][20];
Shark sharks[400];

void cellInit() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            s_map_[i][j].duration = -1;
            s_map_[i][j].owner = -1;
        }
    }
}

void spreadSmell() {
    for (int i = 0; i < M; i++) {
        if (sharks[i].x != -1 && sharks[i].y != -1) {
            s_map_[sharks[i].y][sharks[i].x].duration = k;
            s_map_[sharks[i].y][sharks[i].x].owner = i;
        }
    }
}

void updateDuration() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s_map_[i][j].owner != -1) s_map_[i][j].duration--;
            if (s_map_[i][j].duration == 0) {
                s_map_[i][j].duration = -1;
                s_map_[i][j].owner = -1;
            }
        }
    }
}

void input() {
    cin >> N >> M >> k;
    count = M;
    cellInit();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map_[i][j];
            map_[i][j]--;
            if (map_[i][j] != -1) {
                sharks[map_[i][j]].x = j;
                sharks[map_[i][j]].y = i;
                s_map_[i][j].duration = k;
                s_map_[i][j].owner = map_[i][j];
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> sharks[i].c_dir;
        sharks[i].c_dir--;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> sharks[i].priority[j][k];
                sharks[i].priority[j][k]--;
            }
        }
    }
}

bool mapCheck(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}

int decideDirection(int index) {
    int c_dir = sharks[index].c_dir;
    int x = sharks[index].x;
    int y = sharks[index].y;
    //cout << "Direction check - current dir : " << c_dir << " x : " << x << " y : " << y << endl; 
    for (int i = 0; i < 4; i++) {
        int n_y = y + direction_map[sharks[index].priority[c_dir][i]][1];
        int n_x = x + direction_map[sharks[index].priority[c_dir][i]][0];
        if (mapCheck(n_x, n_y) && s_map_[n_y][n_x].owner == -1) {
            return sharks[index].priority[c_dir][i];
        }
    }

    for (int i = 0; i < 4; i++) {
        int n_y = y + direction_map[sharks[index].priority[c_dir][i]][1];
        int n_x = x + direction_map[sharks[index].priority[c_dir][i]][0];
        if (mapCheck(n_x, n_y) && s_map_[n_y][n_x].owner == index) {
            return sharks[index].priority[c_dir][i];
        }
    }

    return -1;
}

void makeMove() {
    for (int i = 0; i < M; i++) {
        if (sharks[i].x != -1 && sharks[i].y != -1) {
            int dir = decideDirection(i);
            if (dir == -1) {
                cout << "ERROR" << endl;
                return;
            }
            //cout << "Shark Move Test : " << i << " - x : " << sharks[i].x << " y : " << sharks[i].y << " dir : " << dir  << endl;
            map_[sharks[i].y][sharks[i].x] = -1;
            sharks[i].x += direction_map[dir][0];
            sharks[i].y += direction_map[dir][1];
            sharks[i].c_dir = dir;
            int index = map_[sharks[i].y][sharks[i].x];
            map_[sharks[i].y][sharks[i].x] = i;
            if (index != -1) {
                if (i > index) {
                    map_[sharks[i].y][sharks[i].x] = index;
                    sharks[i].x = -1;
                    sharks[i].y = -1;
                } else {
                    sharks[index].x = -1;
                    sharks[index].y = -1;
                }
                count--;
            }
        }
    }
}
void Print() {
    cout << "Time : " << times << endl;
    cout << "Sharks " << endl;
    for (int i = 0; i < M; i++) {
        cout << "Shark " << i << " - x : " << sharks[i].x << " y : " << sharks[i].y << endl;
    }
    cout << "Map " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map_[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Smell Map " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << s_map_[i][j].owner << " ";
        }
        cout << endl;
    }
    cout << "Smell Map duration" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << s_map_[i][j].duration << " ";
        }
        cout << endl;
    }
    cout << "--------------------" << endl;

}

int main() {
    input();
    while (count > 1 && times <= 1000) {
        times++;
        makeMove();
        updateDuration();
        spreadSmell();
    }

    if (times > 1000) times = -1;
    cout << times << endl;

    return 0;
}
