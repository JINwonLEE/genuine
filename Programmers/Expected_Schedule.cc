#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    int a_num = a < b ? a : b;
    int b_num = a < b ? b : a;

    int count = 10;
    while (a_num + 1 != b_num || a_num % 2 == 0) {
        if (a_num % 2 == 0) {
            a_num /= 2;
        } else {
            a_num /= 2;
            a_num++;
        }
        if (b_num % 2 == 0) {
            b_num /= 2;
        } else {
            b_num /= 2;
            b_num++;
        }
        answer++;
    }
    
    return answer;
}
