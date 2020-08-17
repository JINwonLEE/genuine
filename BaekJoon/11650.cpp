#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    pair<int, int>* coord = new pair<int, int>[N];
    for (int i = 0; i < N; i++) scanf("%d%d", &coord[i].first, &coord[i].second);

    sort(coord, coord + N, [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second <= b.second;
            return a.first < b.first;
            });
    
    for (int i = 0; i < N; i++) printf("%d %d\n", coord[i].first, coord[i].second);
    return 0;
}
