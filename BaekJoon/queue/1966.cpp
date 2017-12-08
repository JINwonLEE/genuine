#include <iostream>
#include <queue>

using namespace std;

struct item{
    int index;
    int priority;
};

int find_max(queue<item> Q) {
    int max = 0;
    while(!Q.empty()) {
        if (max < Q.front().priority) {
            max = Q.front().priority;
        }
        Q.pop();
    }

    return max;
}

int main() {
    int Test, number_of_print, index;

    cin >> Test;
    for (int i = 0; i < Test; i++) {
        queue<item> priority;
        int max_pr = 0;
        cin >> number_of_print >> index;
        for (int i = 0; i < number_of_print; i++) {
            item tmp;
            tmp.index = i;
            cin >> tmp.priority;
            if (max_pr < tmp.priority) {
                max_pr = tmp.priority;
            }
            priority.push(tmp);
        }
        int count = 1;
        while(true) {
            item tmp = priority.front();
            priority.pop();
            if (max_pr > tmp.priority) {
                priority.push(tmp);
            }
            else {
                if (tmp.index == index) {
                    cout << count << endl;
                    break;
                }
                else {
                    count++;
                    max_pr = find_max(priority);
                }
            }
        }
    }


    return 0;
}
