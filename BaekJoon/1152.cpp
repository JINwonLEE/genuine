#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string sent;
    vector<string> arr;
    getline(cin, sent);
    
    stringstream ss(sent);
    string tmp;
    while (getline(ss, tmp, ' ')) {
        if (tmp.length() != 0)
            arr.push_back(tmp);
    }
    cout << arr.size() << endl;
    arr.clear();
    
    return 0;
}

