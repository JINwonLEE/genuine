#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> queue;
    for (auto a : scoville) {
        queue.push(a);
    }
    while (queue.top() < K) {
        if (queue.size() == 1) {
            answer = -1;
            break;
        }
        int smallest = queue.top();
        queue.pop();
        int second_smallest = queue.top();
        queue.pop();
        queue.push(smallest + second_smallest * 2);
        answer++;
    }
    return answer;
}
