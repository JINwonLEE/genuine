#include <string>
#include <vector>

using namespace std;

void makeMaximum(int index, int height, vector<vector<int>>& m, const vector<vector<int>>& tr) {
    for (int i = 0; i < tr[index].size(); i++) {
        int max = 0;
        if (i >= 1 && max < m[index-1][i-1] + tr[index][i-1]) {
            max = m[index-1][i-1] + tr[index][i];
        }
        if (i < tr[index - 1].size() && max < m[index-1][i] + tr[index][i]) {
            max = m[index-1][i] + tr[index][i];
        }
        m[index][i] = max;
    }
    if (index != height-1) {
        makeMaximum(index + 1, height, m, tr);
    }    
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    vector<vector<int>> maximum(triangle.size(), vector<int>());
    
    for (int i = 0; i < height; i++) {
        maximum[i].resize(i + 1, 0);
    }
    maximum[0][0] = triangle[0][0];
    makeMaximum(1, height, maximum, triangle);
    int max = 0;
    for (int i = 0; i < height; i++) {
        if (max < maximum[height-1][i]) {
            max = maximum[height-1][i];
        }
    }
    
    return max;
}
