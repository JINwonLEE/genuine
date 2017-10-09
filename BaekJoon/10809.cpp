#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;
    int alphabet[26];
    fill_n(alphabet, 26, -1);

    for (int i = 0; i < word.length(); i++) {
        int order = word[i] - 'a';
        if (alphabet[order] == -1) {
            alphabet[order] = i;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }
    cout << endl;
    
    return 0;
}
