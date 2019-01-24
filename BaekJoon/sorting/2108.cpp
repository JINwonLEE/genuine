#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


int main() {
    int num;
    cin >> num;
    double av_ = 0;
    int mid =  0;
    int freq = 0;
    int interv = 0;
    int* arr = new int[num];
    
    for (int i = 0; i <num; i++) {
        cin >> arr[i];
        av_ += arr[i];
    }
    
    av_ /= (double)num;
    av_ = floor(av_ + 0.5);
    sort(arr, arr + num);
    int fre = 1;
    int max_freq = 1;
    bool check_second = false;
    freq = arr[0];
    for (int i = 1; i < num; i++) {
        if (arr[i-1] == arr[i]) {
            fre++;
        }
        else {
            if (fre > max_freq) {
                check_second = false;
                freq = arr[i-1];
                max_freq = fre;
            }
            else if (fre == max_freq) {
                if (!check_second && freq != arr[i-1]) {
                    freq = arr[i-1];
                    check_second = true;
                }
            }
            fre = 1;
        }
    }
    mid = arr[(num + 1) / 2 - 1];
    interv = arr[num-1] - arr[0];
    
    cout << static_cast<int>(av_) << endl;
    cout << mid << endl;
    cout << freq << endl;
    cout << interv << endl;
    
    
    return 0;
}
