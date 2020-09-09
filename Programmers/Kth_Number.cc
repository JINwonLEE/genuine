#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        int start = commands[i][0];
        int end = commands[i][1];
        int index = commands[i][2] - 1;
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int j = start-1; j < end; j++) {
            queue.push(array[j]);
        }
        while (index--) queue.pop();
        answer.push_back(queue.top());
    }
    return answer;
}
