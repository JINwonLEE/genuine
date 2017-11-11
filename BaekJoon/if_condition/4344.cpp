#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        double sum = 0;
        int *scores = new int[num];
        for (int j = 0; j < num; j++) {
            cin >> scores[j];
            sum += scores[j];
        }
        double avg = (double)(sum / num);
        int num_st = 0;
        for (int j = 0; j < num; j++) {
            if (avg < (double)scores[j]) {
                num_st++;
            }
        }
        cout << fixed << setprecision(3) << (double)num_st / (double)num * 100 << "%\n";
        
        delete [] scores;
    }

    return 0;
}
