#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, M;
    queue<int> queue_;
    int *arr;
    cin >> N >> M;
    arr = new int[N];
    int index = 0;

    for (int i = 1; i <= N; i++) {
        queue_.push(i);
    }

    while (!queue_.empty()) {
        for (int i = 1; i < M; i++) {
            int can = queue_.front();
            queue_.pop();
            queue_.push(can);
        }
        int cand = queue_.front();
        queue_.pop();
        arr[index++] = cand;
    }

    cout << "<";
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i != N-1) {
            cout << ", ";
        }
    }
    cout << ">" << endl;

    delete [] arr;
    return 0;
}
