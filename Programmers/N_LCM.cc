#include <string>
#include <vector>

using namespace std;

int getLCM(int a, int b) {
    int cand = a < b ? b : a;
    while (cand % a != 0 || cand % b != 0) cand++;
    
    return cand;
}

int solution(vector<int> arr) {
    int answer = 0;
    int lcm = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        lcm = getLCM(lcm, arr[i]);
    }
    return lcm;
}
