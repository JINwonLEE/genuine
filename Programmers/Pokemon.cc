#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> num;
    for (auto ele : nums) {
        num.insert(ele);
    }
    if (num.size() > nums.size() / 2) answer = nums.size() / 2;
    else answer = num.size();
    return answer;
}
