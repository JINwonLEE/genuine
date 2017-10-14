#include <iostream>

//void countingSort(int* arr, int size);

using namespace std;

/*
void countingSort(int* arr, int size) {
    int* counting = new int[10001];
    int* tmp = new int[size];
    fill_n(counting, 10001, 0);
    
    for (int i = 0; i < size; i++) {
        counting[arr[i]]++;
    }
    
    for (int i = 0; i < 10001; i++) {
        counting[i] += counting[i -1];
    }
    
    for (int i = 0; i < size; i++) {
        tmp[counting[arr[i]] - 1] = arr[i];
        counting[arr[i]]--;
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = tmp[i];
    }   
    
    delete [] counting;
    delete [] tmp;
}
*/

int main() {
    int num;
    cin >> num;
    int count[10001];
    fill_n(count, 10001, 0);
    
    int val;
    for (int i = 0; i < num; i++) {
        cin >> val;
        count[val]++;
    }
   
    for (int i = 1; i < 10001; i++) {
        count[i] += count[i-1];
    }
    
    for (int i = 1; i < 10001; i++) {
        int diff = count[i] - count[i-1];
        while (diff > 0) {
            cout << i << "\n";
            diff--;
        } 
    }
    

    return 0;
}
