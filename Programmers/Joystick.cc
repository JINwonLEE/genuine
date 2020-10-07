#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int pos = 0;
    string test = "";
    for (int i = 0; i < name.size(); i++) test += "A";
    
    while (name[pos] != 'A' || name != test) {
        int up = name[pos] - 'A';
        int down = 'A' + 26 - name[pos];
        int up_down = up < down ? up : down;
        answer += up_down;
        
        name[pos] = 'A';
        int right = 0;
        for (int i = pos; i < name.size(); i++) {
            if (name[i] != 'A') {
                right = i - pos;
                break;
            }
        }
        int left = 0;
        int tmp = pos;
        while (name[tmp] == 'A' && left < name.size()) {
            tmp = tmp - 1 == -1 ? name.size() - 1 : tmp - 1;
            left++;
        }
        int left_right = pos;
        if (right != 0 && left != name.size()) {
            if (right <= left ) {
                left_right = right;
                pos = right + pos;
            } else {
                left_right = left;
                pos = pos - left < 0 ? pos + name.size() - left : pos - left;
            }
            answer += left_right;
        } else if (right == 0 && left != name.size()) {
            answer += left;
            pos = pos - left < 0 ? pos + name.size() - left : pos - left;
        }
    }
    return answer;
}
