#include <iostream>
#include <algorithm>

using namespace std;

struct item {
    int number;
    int count;
};

bool acompare(item lhs, item rhs) { return lhs.count < rhs.count; }

int main() {
    int room_num;
    cin >> room_num;
    int count_set = 0;
    int digit;
    item number_set[10];
    for (int i = 0; i < 10; i++) {
        number_set[i].number = i;
        number_set[i].count = 0;
    }
    if (room_num == 0) {
        cout << 1 << endl;
        return;
    }
    
    while (room_num > 0) {
        digit = room_num % 10;
        if (digit == 9) {
            digit = 6;
        }
        number_set[digit].count++;
        room_num /= 10;
    }
    int tmp = number_set[6].count;
    number_set[6].count /= 2;
    number_set[9].count = tmp - number_set[6].count;
    
    sort(number_set, number_set + 10, acompare);
    cout << number_set[9].count << endl;
    return 0;
}
