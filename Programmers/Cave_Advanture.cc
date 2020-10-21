#include <vector>
#include <iostream>
using namespace std;

vector<int> m;
vector<vector<int>> v_p;
vector<int> pause;
bool visit[200000];
void findPath(int st) {
    if (visit[st]) return;
    
    if (m[st] != -1 && !visit[m[st]]) {
        pause[m[st]] = st;
        return;
    }
    
    visit[st] = true;
    if (pause[st] != -1)
        findPath(pause[st]);
    for (int i = 0; i < v_p[st].size(); i++) {
        findPath(v_p[st][i]);
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    m.resize(n);
    v_p.resize(n);
    pause.resize(n);
    for (int i = 0; i < n; i++) {
        m[i] = -1;
    }
    for (auto ele : order) {
        m[ele[1]] = ele[0];
    }
    
    for (int i = 0; i < path.size(); i++) {
        v_p[path[i][0]].push_back(path[i][1]);
        v_p[path[i][1]].push_back(path[i][0]);
    }
    
    for (int i = 0; i < n; i++) {
        visit[i] = false;
        pause[i] = -1;
    }
    
    if (m[0] != -1) return false;
    visit[0] = true;
    for (int i = 0 ; i < v_p[0].size(); i++) {
        findPath(v_p[0][i]);
    }
    
    bool answer = true;
    for (int i = 0 ; i < n; i++) {
        if (!visit[i]) {
            answer = false; 
            break;
        }
    }
    
    return answer;
}
