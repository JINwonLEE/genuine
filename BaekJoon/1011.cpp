#include <iostream>

using namespace std;

int main() {
    int case_;
    cin >> case_;
    int start, end;
    
    for (int i = 0; i < case_; i++) {
        cin >> start >> end;
        int st = start;
        int en = end;
        int count = 0;
        int step = 1;
        while (st < en) {
            st += step;
            en -= step;
            step++;
            count += 2;
        }
        if (st != en) {
            count -= 2;
            st -= --step;
            en += step;
            if (en - st <= step) {
                count++;
            }
            else {
                int diff = en - st;
                while (diff > 0) {
                    if (diff <= step) {
                        count++;
                        break;
                    }
                    diff -= step;
                    count++;
                
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
