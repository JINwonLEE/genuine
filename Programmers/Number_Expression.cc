#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int number = 1;
    
    while (number * (number + 1) / 2 <= n) number++;
    
    for (int i = 1; i < number; i++) {
        int sum_of_serial = i * (i-1) / 2;
        int tmp = n - sum_of_serial;
        if (tmp % i == 0) answer++;
    }
    
    return answer;
}
