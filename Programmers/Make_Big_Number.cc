#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int num_length = number.size() - k;
    
    int max_index = -1;
    for (int i = num_length ; i > 0; i--) {
        int index = 0;
        int M = -1;
        for (int j = max_index + 1; j <= number.size() - i; j++) {
            if (M < number[j] - '0') {
                index = j;
                M = number[j] - '0';
            }
        }
        answer.append(to_string(M));
        max_index = index;
    }
    return answer;
}
