#include <string>
#include <vector>

using namespace std;
char Arr[] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

void makeArr(int index, string str, vector<string>& ca) {
    if (index == 9) {
        ca.push_back(str);
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (Arr[i] != '-') {
            str += Arr[i];
            char tmp = Arr[i];
            Arr[i] = '-';
            makeArr(index + 1, str, ca);
            Arr[i] = tmp;
            str = str.substr(0, str.size() - 1);
        }
    }
}

int getIndex(char a, string str) {
    int index = 0;
    for (int i = 0; i < 8; i++) {
        if (a == str[i]) {
            index = i;
            break;
        }
    }
    return index;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string str = "";
    vector<string> ca;
    makeArr(1, str, ca);
    for (int i = 0; i < ca.size(); i++) {
        bool valid = true;
        for (int j = 0; j < n; j++) {
            int a_ind = getIndex(data[j][0], ca[i]);
            int b_ind = getIndex(data[j][2], ca[i]);
            int diff = a_ind < b_ind ? b_ind - a_ind : a_ind - b_ind;
            diff--;
            char op = data[j][3];
            int num = data[j][4] - '0';
            if ((op == '=' && diff != num) ||
                (op == '<' && diff >= num) ||
                (op == '>' && diff <= num)) {
                valid = false;
                break;
            } 
        }
        if (valid) answer++;
    }
    return answer;
}
