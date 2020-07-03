#include <iostream>
#include <string>
#include <locale>
#include <algorithm>

using namespace std;

int main() {
    string st;
    cin >> st;
    int alphabet_[26];
    fill_n(alphabet_, 26, 0);
    locale loc;
    
    for (int i = 0; i < st.length(); i++) {
        st[i] = tolower(st[i], loc);
        alphabet_[st[i] - 'a']++;
    }
    int alphabet[26];
    copy(alphabet_, alphabet_ + 26, alphabet);
    sort(alphabet, alphabet + 26);

    if (alphabet[24] == alphabet[25]) {
        cout << "?" << endl;
    }
    else {
        for (int i = 0; i < 26; i++) {
            if (alphabet[25] == alphabet_[i]) { 
                cout << (char)(i + 'A') << endl;
                break;
            }
        }
    }
    return 0;
}
