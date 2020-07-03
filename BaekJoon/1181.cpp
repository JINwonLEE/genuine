#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool st_compare(string a, string b) { 
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    else {
        int index = 0;
        while (index < a.length()) {
            if (a[index] != b[index]) {
                return a[index] < b[index];
            }
            else {
                index++;
            }
        }
        return false;
    }
}

int main() {
    int num;
    cin >> num;

    string* arr = new string[num];
    
    for (int i = 0; i < num ; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + num, st_compare);
    cout << arr[0] << endl;
    for (int i = 1; i < num; i++) {
        if (arr[i] != arr[i-1]) {
            cout << arr[i] << endl;
        }
    }
        
    delete [] arr;
        
    return 0;
}

