#include <iostream>
#include <string>

using namespace std;

int main() {
    string ch_[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string st;
    
    cin >> st;
    int len = st.length();
    int count = 0;
    
    for (int i = 0; i < len; ) {
        string tmp = "";
        tmp += st[i];
        tmp += st[i+1];
        bool exist = false;
        for (int j = 0; j < 8; j++) {
            if (tmp.compare("dz") == 0 && st[i+2] == '=') {
                i += 3;
                exist = true;
                count++;
                break;
            }
            if (tmp.compare(ch_[j]) == 0) {
                i += 2;
                exist = true;
                count++;
                break;
            }
        }   
        if (!exist) {
            i += 1;
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}
