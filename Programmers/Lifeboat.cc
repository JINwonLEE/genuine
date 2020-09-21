#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int len = people.size();
    sort(people.begin(), people.end());
    int index = 0;
    int la_index = len - 1;
    while (index <= la_index) {
        if (index == la_index) {
            answer++;
            break;
        }
        if (people[la_index] + people[index] <= limit) {
            la_index--;
            index++;
        } else {
            la_index--;
        }
        answer++;
    }
    return answer;
}
