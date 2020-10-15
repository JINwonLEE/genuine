#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct coord {
    int x;
    int y;
};

struct item {
    int num;
    int id;
};

int N, score = 0, g_remain = 0, b_remain = 0;
vector<pair<int, coord>> blocks;
item g_map[6][4];
item b_map[4][6];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t;
        coord tmp;
        cin >> t >> tmp.x >> tmp.y;
        blocks.push_back({t, tmp});
    }
}

void init() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            g_map[i][j].num = 0;
            b_map[j][i].num = 0;
            g_map[i][j].id = -1;
            b_map[j][i].id = -1;
        }
    }
}

int getXcoord(int y, int st) {
    int c = -1;
    for (int i = st; i < 6; i++) {
        if (g_map[i][y].num != 0) {
            c = i;
            break;
        }
    }
    return c == -1 ? 5 : c - 1;
}

int getYcoord(int x, int st) {
    int c = -1;
    for (int i = st; i < 6; i++) {
        if (b_map[x][i].num != 0) {
            c = i;
            break;
        }
    }
    return c == -1 ? 5 : c -1;
}

int invElement(int x, int y) {
    if (y < 3 && g_map[x][y].id == g_map[x][y+1].id) return 1; 
    if (y > 0 && g_map[x][y].id == g_map[x][y-1].id) return -1; 
    return 0;
}

void updateLine() {
    bool needUpdate = true;
    while (needUpdate) {
        needUpdate = false;
        int break_line_index = -1;
        for (int i = 5; i > 1; i--) {
            bool getScore = true;
            for (int j = 0; j < 4; j++) {
                if (g_map[i][j].num == 0) {
                    getScore = false;
                    break;
                }
            }
            
            if (getScore) {
                needUpdate = true;
                if (break_line_index == -1) break_line_index = i;
                for (int j = 0; j < 4; j++) {
                    g_map[i][j].num = 0;
                    g_map[i][j].id = -1;
                }
                score++;
            }
        }

        if (needUpdate) {
            for (int i = break_line_index - 1; i >= 0; i--) {
                for (int j = 0; j < 4; j++) {
                    int x;
                    int pairing = invElement(i, j);
                    if (pairing == 0) {
                        x = getXcoord(j, i+1);
                    } else {
                        x = min(getXcoord(j, i+1), getXcoord(j+pairing, i+1));
                        g_map[x][j+pairing].num = g_map[i][j].num;
                        g_map[x][j+pairing].id = g_map[i][j].id;
                        g_map[i][j+pairing].num = 0;
                        g_map[i][j+pairing].id = -1;
                    }
                    g_map[x][j].num = g_map[i][j].num;
                    g_map[x][j].id = g_map[i][j].id;
                    g_map[i][j].num = 0;
                    g_map[i][j].id = -1;
                }
            }
        }
    }
}

int invBElement(int x, int y) {
    if (x < 3 && b_map[x][y].id == b_map[x+1][y].id) {return 1;} 
    if (x > 0 && b_map[x][y].id == b_map[x-1][y].id) {return -1;} 
    return 0;
}

void updateBLine() {
    bool needUpdate = true;
    while (needUpdate) {
        needUpdate = false;
        int break_line_index = -1;
        for (int i = 5; i > 1; i--) {
            bool getScore = true;
            for (int j = 0; j < 4; j++) {
                if (b_map[j][i].num == 0) {
                    getScore = false;
                    break;
                }
            }
            
            if (getScore) {
                needUpdate = true;
                if (break_line_index == -1) break_line_index = i;
                for (int j = 0; j < 4; j++) {
                    b_map[j][i].num = 0;
                    b_map[j][i].id = -1;
                }
                score++;
            }
        }
        if (needUpdate) {
            for (int i = break_line_index - 1; i >= 0; i--) {
                for (int j = 0; j < 4; j++) {
                    int y;
                    int pairing = invBElement(j, i);
                    if (pairing == 0) {
                        y = getYcoord(j, i+1);
                    } else {
                        y = min(getYcoord(j, i+1), getYcoord(j+pairing, i+1));
                        b_map[j+pairing][y].num = b_map[j+pairing][i].num;
                        b_map[j+pairing][y].id = b_map[j+pairing][i].id;
                        b_map[j+pairing][i].num = 0;
                        b_map[j+pairing][i].id = -1;
                    }
                    b_map[j][y].num = b_map[j][i].num;
                    b_map[j][y].id = b_map[j][i].id;
                    b_map[j][i].num = 0;
                    b_map[j][i].id = -1;
                }
            }
        }
    }
}

void updateBMap(int type, coord en_coord, int id) {
    if (type == 1) {
        b_map[en_coord.x][en_coord.y].num = 1;
        b_map[en_coord.x][en_coord.y].id = id;
    } else if (type == 2) {
        b_map[en_coord.x][en_coord.y].num = 2;
        b_map[en_coord.x][en_coord.y + 1].num = 2;
        b_map[en_coord.x][en_coord.y].id = id;
        b_map[en_coord.x][en_coord.y + 1].id = id;
    } else {
        b_map[en_coord.x][en_coord.y].num = 3;
        b_map[en_coord.x+1][en_coord.y].num = 3;
        b_map[en_coord.x][en_coord.y].id = id;
        b_map[en_coord.x+1][en_coord.y].id = id;
    }

    updateBLine();
    int st = -1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0 ; j < 4; j++) {
            if (b_map[j][i].num != 0) {
                st = i;
                break;
            }
        }
        if (st != -1) break;
    }
    if (st != -1) {
        for (int i = 3+st; i >= st; i--) {
            for (int j = 0; j < 4; j++) {
                int add = st == 0 ? 2 : 1;
                b_map[j][i+add].num = b_map[j][i].num; 
                b_map[j][i+add].id = b_map[j][i].id; 
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                b_map[j][i].num = 0;
                b_map[j][i].id = -1;
            }
        }
    }

}

void updateMap(int type, coord en_coord, int id) {
    if (type == 1) {
        g_map[en_coord.x][en_coord.y].num = 1;
        g_map[en_coord.x][en_coord.y].id = id;
    } else if (type == 2) {
        g_map[en_coord.x][en_coord.y].num = 2;
        g_map[en_coord.x][en_coord.y + 1].num = 2;
        g_map[en_coord.x][en_coord.y].id = id;
        g_map[en_coord.x][en_coord.y + 1].id = id;
    } else {
        g_map[en_coord.x][en_coord.y].num = 3;
        g_map[en_coord.x+1][en_coord.y].num = 3;
        g_map[en_coord.x][en_coord.y].id = id;
        g_map[en_coord.x+1][en_coord.y].id = id;
    }

    updateLine();
    int st = -1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0 ; j < 4; j++) {
            if (g_map[i][j].num != 0) {
                st = i;
                break;
            }
        }
        if (st != -1) break;
    }
    if (st != -1) {
        for (int i = 3+st; i >= st; i--) {
            for (int j = 0; j < 4; j++) {
                int add = st == 0 ? 2 : 1;
                g_map[i+add][j].num = g_map[i][j].num; 
                g_map[i+add][j].id = g_map[i][j].id; 
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                g_map[i][j].num = 0;
                g_map[i][j].id = -1;
            }
        }
    }

}

void moveToGreen(int i) {
    int type = blocks[i].first;
    coord en_coord;
    coord st_coord = blocks[i].second;
    en_coord.y = st_coord.y;

    if (type == 1) {
        en_coord.x = getXcoord(en_coord.y, 2); 
    } else if (type == 3) {
        en_coord.x = getXcoord(en_coord.y, 2); 
        en_coord.x--;
    } else {
        en_coord.x = min(getXcoord(en_coord.y, 2), getXcoord(en_coord.y+1, 2)); 
    }

    updateMap(type, en_coord, i);
}

void moveToBlue(int i) {
    int type = blocks[i].first;
    coord en_coord;
    coord st_coord = blocks[i].second;
    en_coord.x = st_coord.x;

    if (type == 1) {
        en_coord.y = getYcoord(en_coord.x, 2);
    } else if (type == 2) {
        en_coord.y = getYcoord(en_coord.x, 2);
        en_coord.y--;
    } else {
        en_coord.y = min(getYcoord(en_coord.x, 2), getYcoord(en_coord.x+1, 2)); 
    }
    updateBMap(type, en_coord, i);
}

void moveBlocks(int i) {
    moveToGreen(i);
    moveToBlue(i);
}


int main() {
    input();
    init();

    for (int i = 0; i < N; i++) {
        moveBlocks(i);
    }

    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (g_map[i][j].num != 0) g_remain++;
            if (b_map[j][i].num != 0) b_remain++;
        }
    }

    cout << score << endl;
    cout << g_remain + b_remain << endl;

    return 0;
}
