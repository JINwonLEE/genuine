#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {
        int dur = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                dur = j - i;
                break;
            }
        }
        if (dur == 0) {
            dur = prices.size() - i - 1;
        }
        answer.push_back(dur);
    }
    return answer;
}
