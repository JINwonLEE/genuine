#include <iostream>

using namespace std;
int vertex[1001];
int edge[1001][1001];
int visit_dfs[1001];
int visit_bfs[1001];
int queue_[1001];
int front_ = 0;
int rear_ = 0;

void dfs(int v) {
    cout << v << " ";
    visit_dfs[v] = true;
    for (int i = 1; i < 1001; i++) {
        if (edge[v][i] == true && visit_dfs[i] == false) {
            dfs(i);
        }
    }
}

void bfs(int v) {
    queue_[rear_++] = v;
    visit_bfs[v] = true;

    int pr;
    while (front_ != rear_) {
        pr = queue_[front_++];
        cout << pr << " ";

        for (int i = 1; i < 1001; i++) {
            if (edge[pr][i] == true && visit_bfs[i] == false) {
                queue_[rear_++] = i;
                visit_bfs[i] = true;
            }
        }
    }
}

int main() {
    int Vnum, Enum, st;
    cin >> Vnum >> Enum >> st;

    int from, to;
    for (int i = 0; i < Enum; i++) {
        cin >> from >> to;
        edge[from][to] = true;
        edge[to][from] = true;
    }

    dfs(st);
    cout << "\n";

    bfs(st);
    cout << "\n";
    
}
