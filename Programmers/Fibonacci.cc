#include <string>

using namespace std;

int solution(int n) {
    int f0 = 0;
    int f1 = 1;
    for (int i = 0; i < n; i++) {
        int tmp = f1;
        f1 = (f1 + f0) % 1234567;
        f0 = tmp % 1234567;
    }
    
    return f0;
}
