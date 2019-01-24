#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
long long number[200005];
int real_number[200005];

int main(int argc, char** argv)
{
    int T, test_case;
    scanf("%d",&T);
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;

        long long number_of_list;
        scanf("%lld", &number_of_list);

        long long max_ = 0;
        for (int i = 0 ; i < number_of_list; i++) {
            long long num;
            real_number[i] = 0;
            scanf("%lld", &num);
            number[i] = num;
            if (number[i] > max_) {
                max_ = num;
                real_number[i]++;
            }
        }
        long long min_ = 10000001;
        for (int i = number_of_list - 1; i >= 0; i--) {
            if (number[i] < min_) {
                min_ = number[i];
                real_number[i]++;
                if (real_number[i] == 2) {
                    Answer++;
                }
            }           
        }
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
