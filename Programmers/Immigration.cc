#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long min_time = 1;
    long long max_time = times[times.size() - 1] * (long long)n;
    long long answer = 0;
    
    while (min_time <= max_time) {
        long long mid_time = (min_time + max_time) / 2;
        long long people = 0;
        for (auto t : times) {
            people += mid_time / t;
        }
        
        if (people >= n) {
            answer = mid_time;
            max_time = mid_time - 1;
        } else {
            min_time = mid_time + 1;
        }
    }
    return answer;
}
