#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x = 3, y = 3;
    while (true) {
        if ((x+y) * 2 - 4 == brown && (x-2) * (y-2) == yellow) {
            answer.push_back(x);
            answer.push_back(y);
            break;
        }
        if (x == y) {
            x++;
            y = 3;
        } else {
            y++;
        }
    }    
    return answer;
}
