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
    
    while (room_num > 0) {
        digit = room_num % 10;
        number_set[digit].count++;
        room_num /= 10;
    }
    
    sort(number_set, number_set + 10, acompare);
    
    int ind = 0;
    if (number_set[9].number != 6 && number_set[9].number != 9) {
        count_set = number_set[9].count;
    }
    else if (number_set[9].number == 6) {
        for (int i = 0; i < 10; i++) {
            if (number_set[i].number == 9) {
                ind = i;
                break;
            }
        }
        while (number_set[9].count - number_set[ind].count > 1) {
            number_set[9].count--;
            number_set[ind].count++;
        }
        sort(number_set, number_set + 10, acompare);       
        count_set = number_set[9].count;
    }
    else {
       for (int i = 0; i < 10; i++) {
            if (number_set[i].number == 6) {
                ind = i;
                break;
            }
        }
        while (number_set[9].count - number_set[ind].count > 1) {
            number_set[9].count--;
            number_set[ind].count++;
        }
        sort(number_set, number_set + 10, acompare);       
        count_set = number_set[9].count;
    }
    
    cout << count_set << endl;
    return 0;
}
