#include <string>
#include <vector>

using namespace std;
int num = 0;

void getNum(int n) {
    while (n > 0) {
        if (n % 2 == 1) num++;
        n /= 2;
    }
}

bool isSame(int cand) {
    int count = 0;
    while (cand > 0) {
        if ( cand % 2 == 1) count++;
        cand /= 2;
    }
    
    return count == num;
}

int solution(int n) {
    int answer = 0;
    getNum(n);
    
    int next = n + 1;
    while (true) {
        if (isSame(next)) {
            answer = next;
            break;
        }
        next++;
    }
    return answer;
}
