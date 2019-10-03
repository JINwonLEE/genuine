#include <math.h>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int num;
    double average_double = 0;
    int mid = 0;
    int freq = 0;
    int interv = 0;
    int arr[500000];
    int count[8001];
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
        count[4000 + arr[i]] += 1;
        average_double += (double)arr[i];
    }

    average_double /= (double)num;
    average_double = floor(average_double + 0.5);

    int frequency_count = 0;
    int second_frequency_count = 0;
    int freq_num = 0;
    for (int i = 0; i < 8001; i++) {
        if (count[i] > 0) {
            if (frequency_count < count[i]) {
                frequency_count = count[i];
                int tmp = i;
                tmp -= 4000;
                freq_num = tmp;
            } else if (frequency_count == count[i] &&
                       second_frequency_count < count[i]) {
                second_frequency_count = count[i];
                int tmp = i;
                tmp -= 4000;
                freq_num = tmp;
            }
        }
    }
    sort(arr, arr + num);
    mid = arr[(num + 1) / 2 - 1];
    interv = arr[num - 1] - arr[0];

    cout << static_cast<int>(average_double) << endl;
    cout << mid << endl;
    cout << freq_num << endl;
    cout << interv << endl;

    return 0;
}
