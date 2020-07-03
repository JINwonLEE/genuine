#include <iostream>
#include <string>

using namespace std;

int main() {
    int num_words;
    cin >> num_words;
    int count = 0;
    
    for (int i = 0; i < num_words; i++) {
        string words;
        cin >> words;
        int freq[26];
        fill_n(freq, 26, 0);
        bool is_c = true;
        for (int j = 0; j < words.length(); j++) {
            int ind = words[j] - 'a';
            if (freq[ind] != 0 && j != 0 && words[j-1] != words[j]) {
                is_c = false;
                continue;
            }
            else if (freq[ind] == 0) {
                freq[ind]++;
            }   
        }    
        if (is_c) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}
