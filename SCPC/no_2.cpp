#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int number[10001];
int pel[198];

struct Greater
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

void make_number() {
    int index = 0;

    for (int i = 1; i <= 10000; i++) {
        number[i] = 4;
    }

    for (int i = 1; i <= 9; i++) {
        number[i] = 1;
        pel[index++] = i;
    }
    for (int i = 1; i <= 9; i++) {
        number[11 * i] = 1;
        pel[index++] = 11 * i;
    }

    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            number[101 * i + 10 * j] = 1;
            pel[index++] = 101 * i + 10 * j;
        }
    }

    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            number[110 * j + 1001 * i] = 1;
            pel[index++] = 110 * j + 1001 * i;
        }
    }

    for (int i = 0; i < 198; i++) {
        for (int j = i; j < 198; j++) {
            if (pel[i] + pel[j] < 10000 && number[pel[i] + pel[j]] > number[pel[i]] + number[pel[j]]) {
                number[pel[i] + pel[j]] = number[pel[i]] + number[pel[j]];
            }
        }
    }
}

int main(int argc, char** argv)
{
    int T, test_case, Answer;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using cin function.
       You may remove the comment symbols(//) in the below statement and use it.
       Use #include<cstdio> or #include <stdio.h> to use the function in your program.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */

    // freopen("input.txt", "r", stdin);

    //case 504 = 252 + 252
    make_number();

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {

        Answer = 0;
        int N;
        cin >> N;
        int count = 0;
        vector<int> buc;

        if (number[N] == 1) {
            buc.push_back(N);
            N = 0;
        }
        else if (number[N] == 2) {
           for (int i = 0; i < 198; i++) {
               int num = N - pel[i];
               if (number[num] == 1) {
                   buc.push_back(num);
                   buc.push_back(pel[i]);
                   sort(buc.begin(), buc.end(), Greater());
                   N = 0;
                   break;
               }
           }
        }
        else {
            for (int i = 0; i < 198; i++) {                
                int num = N - pel[i];
                if (number[num] != 4) {
                    if (number[num] == 1) {
                        number[N] = 2;
                        buc.push_back(num);
                        buc.push_back(pel[i]);
                        sort(buc.begin(), buc.end(), Greater());
                        N = 0;
                        break;
                    }
                    else if (number[num] == 2) {
                        int max_ = pel[i];
                        int N_ = N - pel[i];
                        for (int j = 0; j < 198; j++) {
                           int num = N_ - pel[j];
                           if (number[num] == 1) {
                               buc.push_back(num);
                               buc.push_back(pel[i]);
                               buc.push_back(pel[j]);
                               sort(buc.begin(), buc.end(), Greater());
                               N = 0;
                               break;
                           }
                        }
                    }
                }
                if (N == 0) {
                    break;
                }
            }

        }

        cout << "Case #" << test_case+1 << endl;
        if (N == 0) {
            cout << buc.size() << " ";
            for (int i = 0; i < buc.size(); i++) {
                cout << buc[i];
                if (i != buc.size() -1 ) {
                    cout << " ";
                }
            }
            cout << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

    return 0;//Your program should return 0 on normal termination.
}
