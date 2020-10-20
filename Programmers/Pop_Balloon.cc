#include <string>
#include <vector>

using namespace std;
struct item {
    int left;
    int right;
};

int solution(vector<int> a) {
    int answer = 0;
    vector<item> check;
    for (int i = 0; i < a.size(); i++) {
        check.push_back({-1, -1});
    }
    int min_index = 0;
    check[0].left = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[min_index]) {
            min_index = i;
        }
        check[i].left = min_index;
    }
    min_index = a.size() - 1;
    check[min_index].right = min_index;
    for (int i = a.size() - 2; i >= 0; i--) {
        if (a[i] < a[min_index]) {
            min_index = i;
        }
        check[i].right = min_index;
    }
    for (int i = 0; i < a.size(); i++) {
        if (check[i].left == i || check[i].right == i) answer++;
    }
    
    return answer;
}
