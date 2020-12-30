#include <vector>
using namespace std;

bool isPrime(int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int k = i + 1; k < nums.size(); k++) {
            for (int j = k + 1; j < nums.size(); j++) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (isPrime(tmp)) {
                    answer++;
                }
            }
        }
    }

    return answer;
}
