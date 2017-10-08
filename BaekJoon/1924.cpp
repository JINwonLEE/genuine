#include <iostream>

using namespace std;

int main() {
    int month, date;
    string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int month_to_date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    cin >> month >> date;
    
    int cal = -1;
    
    if (month > 1) {
        for (int i = 0; i < month-1; i++)
            cal += month_to_date[i];
    }
    cal += date;
    
    cout << day[cal % 7] << endl;
    
    return 0;
}
