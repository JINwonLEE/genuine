#include <iostream>
#include <string>

using namespace std;

int main() {
    int case_;
    cin >> case_;
    char c = 'O';
    char w = 'X';
    string scores;

    for (int i = 0; i < case_; i++) {
        cin >> scores;
        int sum = 0;
        int score_ = 1;
        for (int j = 0; j < scores.length(); j++) {
            if (scores[j] == c) {
                sum += score_++;
            }
            else {
                score_ = 1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
