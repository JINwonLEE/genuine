#include <iostream>
#include <string>
using namespace std;

int main() {
    string st;
    cin >> st;
    int len = st.length();
    int time[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;

    for (int i = 0; i < len; i++) {
        switch(st[i]) {
            case 'A' :
                sum += time[1];
                break;
            case 'B' :
                sum += time[1];
                break;
            case 'C' :
                sum += time[1];
                break;
            case 'D' :
                sum += time[2];
                break;
            case 'E' :
                sum += time[2];
                break;
            case 'F' :
                sum += time[2];
                break;
            case 'G' :
                sum += time[3];
                break;
            case 'H' :
                sum += time[3];
                break;
            case 'I' :
                sum += time[3];
                break;
            case 'J' :
                sum += time[4];
                break;
            case 'K' :
                sum += time[4];
                break;
            case 'L' :
                sum += time[4];
                break;
            case 'M' :
                sum += time[5];
                break;
            case 'N' :
                sum += time[5];
                break;
            case 'O' :
                sum += time[5];
                break;
            case 'P' :
                sum += time[6];
                break;
            case 'Q' :
                sum += time[6];
                break;
            case 'R' :
                sum += time[6];
                break;
            case 'S' :
                sum += time[6];
                break;
            case 'T' :
                sum += time[7];
                break;
            case 'U' :
                sum += time[7];
                break;
            case 'V' :
                sum += time[7];
                break;
            case 'W' :
                sum += time[8];
                break;
            case 'X' :
                sum += time[8];
                break;
            case 'Y' :
                sum += time[8];
                break;
            default :
                sum += time[8];
        }
    }
    cout << sum << endl;
    
    return 0;
}

