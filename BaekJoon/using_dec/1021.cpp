#include <iostream>
#include <deque>

using namespace std;


int getNumOfCircle(int extract_, deque<int>& arr, int& len) {
    bool forward = true;
    int count = 0;
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == extract_) {
            index = i;
        }
    }
    if (index > len - index) {
        forward = false;
    }

    if (forward) {
        int element = arr.front();
        while (extract_ != element) {
            arr.pop_front();
            arr.push_back(element);
            element = arr.front();
            count++;
        }
        arr.pop_front();
        len--;
    }
    else {
        int element = arr.back();
        while (extract_ != element) {
            arr.pop_back();
            arr.push_front(element);
            element = arr.back();
            count++;
        }
        arr.pop_back();
        arr.push_front(element);
        arr.pop_front();
        count++;
        len--;
    }
    
    return count;
}

int main() {
    int length_ = 0;
    int num_of_extract = 0;

    cin >> length_ >> num_of_extract;
    deque<int> order;
    for (int i = 0; i < length_; i++) {
        order.push_back(i+1);
    }

    
    
    // Get the order of extraction
    int ext = 0;
    int count = 0;
    for (int i = 0; i < num_of_extract; i++) {
        cin >> ext;
        int tmp;
        tmp = getNumOfCircle(ext, order, length_);
        count += tmp;
    }
    cout << count << endl;

    return 0;
}
