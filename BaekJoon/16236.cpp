#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>

using namespace std;
int map_[20][20];
int N, shark_x, shark_y, shark_size = 2, count_eat = 0;
int target_x = -1, target_y = -1, times = 0;
vector<pair<int, int>> possible_eat;
bool visit[20][20];

struct item {
    int dist;
    int x, y;
};

void input() {
    cin >> N;
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            cin >> map_[i][j];
            if (map_[i][j] == 9) {
                shark_y = i;
                shark_x = j;
            }
        }
    }
}
                
void growShark() {
    map_[shark_y][shark_x] = 0;

    shark_y = target_y;
    shark_x = target_x;
    map_[shark_y][shark_x] = 9;
    count_eat++;

    target_x = -1;
    target_y = -1;

    if (count_eat == shark_size) {
        count_eat = 0;
        shark_size++;
    }
}

void Print() {
    cout << "-------------" << endl;
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            cout << map_[i][j] << " ";
        }
        cout << endl;
    }
}

struct Comp {
    bool operator()(const item& a, const item& b) {
        if (a.dist == b.dist) {
            if (a.y == b.y) {
                return a.x > b.x;
            }
            return a.y < b.y;
        }

        return a.dist > b.dist;
    }
};

bool findAndDecideFish() {
    priority_queue<item, vector<item>, Comp> q;
    q.push({0, shark_x, shark_y});

    while (!q.empty()) {
        int len = q.size();
        //cout << "WHILE START" << endl;
        for (int i = 0; i < len; i++) {
            item cur = q.top();
            q.pop();
            int x = cur.x;
            int y = cur.y;
            int dist = cur.dist;
            //cout << "Visit Test - X : " << x << " Y : " << y << " Dist : " << dist << " size : " << map_[y][x] << endl; 
            if (map_[y][x] < shark_size && map_[y][x] != 0) {
                target_x = x;
                target_y = y;
                times += dist;
                //cout << "----Target Test - X : " << x << " Y : " << y << " Dist : " << dist << " size : " << map_[y][x] << endl; 
                return true;
            }
            if (x >= 1 && !visit[y][x-1] && map_[y][x-1] <= shark_size) { q.push({dist + 1, x-1, y}); visit[y][x-1] = true;}
            if (x < N-1 && !visit[y][x+1] && map_[y][x+1] <= shark_size) { q.push({dist + 1, x+1, y}); visit[y][x+1] = true;}
            if (y >= 1 && !visit[y-1][x] && map_[y-1][x] <= shark_size) { q.push({dist + 1, x, y-1}); visit[y-1][x] = true;}
            if (y < N-1 && !visit[y+1][x] && map_[y+1][x] <= shark_size) { q.push({dist + 1, x, y+1}); visit[y+1][x] = true;}
        }
    }
    return false;
}

void initVisit() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visit[i][j] = false;
        }
    }
}

int main() {
    input();
    initVisit();
    while (findAndDecideFish()) {
        growShark();
        initVisit();
    }

    cout << times << endl;
    return 0;
}
