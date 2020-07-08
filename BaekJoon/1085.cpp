#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    
    cout << min(min(min(x, w - x), y), h - y) << endl;
    return 0;
}
