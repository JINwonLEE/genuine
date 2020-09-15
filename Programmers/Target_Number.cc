#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    if (numbers.size() == 1) {
        return numbers[0] == target || numbers[0] * -1 == target;
    }
    int last = numbers[numbers.size() - 1];
    numbers.pop_back();
    return solution(numbers, target - last) + solution(numbers, target + last);
}
