#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    size_t length = n * (n+1) / 2;
    vector<int> answer(length, 0);
    int dir = 0; // 0 = down, 1 = right, 2 = up
    int level = 1;
    int count = 0;
    int max_count = n;
    int index = 0;
    for (int i = 1; i <= length; i++) {
        answer[index] = i;
        count++;
        if (count == max_count) {
            dir = dir == 2 ? 0 : dir + 1;
            max_count--;
            count = 0;
        }
        if (dir == 0) {
            index = level + index;
            level++;
        } else if (dir == 1) {
            index++;
        } else if (dir == 2) {
            index = index - level;
            level--;
        }
        
    }
    return answer;
}
