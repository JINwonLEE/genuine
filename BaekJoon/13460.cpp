#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;

struct item{
    int depth;
    int r_x, r_y, b_x, b_y;
};

int r_x, r_y, b_x, b_y;
vector<vector<char>> map_;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool visit[10][10][10][10] = {false,};

void movement(int& x, int& y, int direction) {
    while (map_[y][x] != '#') {
        if (map_[y][x] == 'O') break;
        y += dir[direction][0];
        x += dir[direction][1];
    }
    if (map_[y][x] == '#') {
        y -= dir[direction][0];
        x -= dir[direction][1];
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    map_.resize(M);
    for (int i = 0; i < M; i++) {
        map_[i].resize(N);
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map_[i][j];
            if (map_[i][j] == 'R') {
                r_x = j;
                r_y = i;
                map_[i][j] = '.';
            } else if (map_[i][j] == 'B') {
                b_x = j;
                b_y = i;
                map_[i][j] = '.';
            } 
        }
    }

    queue<item> q;
    q.push({0, r_x, r_y, b_x, b_y});
    visit[r_x][r_y][b_x][b_y] = true;

    while (!q.empty()) {
        item cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int t_r_x = cur.r_x;
            int t_r_y = cur.r_y;
            int t_b_x = cur.b_x;
            int t_b_y = cur.b_y;
            movement(t_r_x, t_r_y, i);
            movement(t_b_x, t_b_y, i);

            if (map_[t_b_y][t_b_x] == 'O') {
                continue;            
            }
            
            if (t_r_x == t_b_x && t_r_y == t_b_y) {
                if (abs(t_r_x - cur.r_x) + abs(t_r_y - cur.r_y) > abs(t_b_x - cur.b_x) + abs(t_b_y - cur.b_y)) {
                    if (t_r_x == cur.r_x) {
                        if (t_r_y < cur.r_y) {
                            t_r_y++;
                        } else {
                            t_r_y--;
                        }
                    } else {
                        if (t_r_x < cur.r_x) {
                            t_r_x++;
                        } else {
                            t_r_x--;
                        }
                    }
                } else {
                    if (t_b_x == cur.b_x) {
                        if (t_b_y < cur.b_y) {
                            t_b_y++;
                        } else {
                            t_b_y--;
                        }
                    } else {
                        if (t_b_x < cur.b_x) {
                            t_b_x++;
                        } else {
                            t_b_x--;
                        }
                    }
                }
            }

            if (map_[t_r_y][t_r_x] == 'O') {
                cout << cur.depth + 1 << endl;
                return 0;
            }

            if (cur.depth == 10) {
                cout << -1 << endl;
                return 0;
            }

            if (!visit[t_r_x][t_r_y][t_b_x][t_b_y]) {
                visit[t_r_x][t_r_y][t_b_x][t_b_y] = true;
                q.push({cur.depth + 1, t_r_x, t_r_y, t_b_x, t_b_y});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
