#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days_to_finish;
    int len = progresses.size();
    for (int i = 0; i < len; i++) {
        days_to_finish.push_back((100 - progresses[i] + speeds[i] - 1) / speeds[i]);
    }

    int index = 0;
    while (index < len) {
        int count = 1;
        int threshold = days_to_finish[index++];
        while (index <= len-1 && threshold >= days_to_finish[index]) {
            index++;
            count++;
        }
        answer.push_back(count);
    }
    return answer;
}
