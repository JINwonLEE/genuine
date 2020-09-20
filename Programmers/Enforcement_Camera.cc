#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int cam_end = routes[0][1];
    for (int i = 0; i < routes.size() - 1; i++) {
        if (cam_end > routes[i][1]) cam_end = routes[i][1];
        if (cam_end < routes[i+1][0]) {
            cam_end = routes[i+1][1];
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp, tmp2;
        cin >> tmp >> tmp2;
        vector<int> ve{tmp, tmp2};
        v.push_back(ve);
    }
    cout << solution(v) << endl;

    return 0;
}

