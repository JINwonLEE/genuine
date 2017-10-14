#include <iostream>

void mergeSort(int* arr, int l, int r);
void merge(int* arr, int l, int m, int r);
using namespace std;


void mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = (l+r) / 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
}
        
void merge(int* arr, int l, int m, int r) {
    int l_size = m - l + 1;
    int r_size = r - m;
    
    int* l_temp = new int[l_size];
    int* r_temp = new int[r_size];
    
    for (int i = 0; i < l_size; i++) {
        l_temp[i] = arr[l + i];
    }
    for (int i = 0; i < r_size; i++) {
        r_temp[i] = arr[m + 1 + i];
    }
    
    int i = 0;
    int j = 0;
    int index = l;
    while (i < l_size && j < r_size) {
        if (l_temp[i] <= r_temp[j]) {
            arr[index] = l_temp[i];
            i++;
        }
        else {
            arr[index] = r_temp[j];
            j++;
        }
        index++;
    }
    
    while (i < l_size) {
        arr[index] = l_temp[i];
        i++;
        index++;
    }

    while (j < r_size) {
        arr[index] = r_temp[j];
        j++;
        index++;
    }
    
    delete [] l_temp;
    delete [] r_temp;
}

int main() {
    int num_;
    cin >> num_;
    int* arr = new int[num_]; 
    
    for (int i = 0; i < num_; i++) {
        cin >> arr[i];
    }
    
    mergeSort(arr, 0, num_-1);
    for (int i = 0; i < num_; i++) {
        cout << arr[i] << "\n";
    }
    
    delete [] arr;
     
    return 0;
}


