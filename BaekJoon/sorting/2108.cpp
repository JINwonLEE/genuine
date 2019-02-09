#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

bool compare_ ( const pair<int, int>& a,  const pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    int num;
    cin >> num;
    double av_ = 0;
    int mid =  0;
    int freq = 0;
    int interv = 0;
    int* arr = new int[num];
    map<int, int> frequency_list;
    
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
        if (frequency_list.find(arr[i]) == frequency_list.end()) {
            frequency_list[arr[i]] = 1;
        }  
        else {
            frequency_list[arr[i]] += 1;
        }
        av_ += static_cast<double>(arr[i]);
    }
    
    av_ /= (double)num;
    av_ = floor(av_ + 0.5);
    //sort(frequency_list.begin(), frequency_list.end(), [=](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second;});
    sort(frequency_list.begin(), frequency_list.end(), compare_);
    sort(arr, arr + num);
    map<int, int>::const_iterator it = frequency_list.begin();
    freq = (it++)->first;
    /*  
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
    */
    mid = arr[(num + 1) / 2 - 1];
    interv = arr[num-1] - arr[0];
    
    cout << static_cast<int>(av_) << endl;
    cout << mid << endl;
    cout << freq << endl;
    cout << interv << endl;
    
    return 0;
}
