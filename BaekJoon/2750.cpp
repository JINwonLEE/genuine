#include <iostream>

void quick_sort(int* arr, int size);
void quick_sort_aux(int* arr, int st, int en);
int partition(int* arr, int st, int en);

using namespace std;

int main() {
    int num;
    cin >> num;
    int* arr = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    quick_sort(arr, num);  

    for (int i = 0; i < num; i++) {
        cout << arr[i] << endl;
    }
    delete [] arr;
    
    return 0;
}

int partition(int* arr, int st, int en) {
    int pivot, index, tmp;
    pivot = arr[en];
    index = st - 1;
    for (int i = st; i < en; i++) {
        if (arr[i] <= pivot) {
            index++;
            tmp = arr[i];
            arr[i] = arr[index];
            arr[index] = tmp;
        }
    }
    tmp = arr[en];
    arr[en] = arr[index + 1];
    arr[index + 1] = tmp;
    return index + 1;
}

void quick_sort_aux(int* arr, int st, int en) {
    int q;
    if (st < en) {
        q = partition(arr, st, en);
        quick_sort_aux(arr, st, q-1);
        quick_sort_aux(arr, q+1, en);
    }
}

void quick_sort(int* arr, int size) {
    quick_sort_aux(arr, 0, size - 1);    
}
