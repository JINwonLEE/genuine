#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

string toLow(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int time = 0;
    deque<string> cache;
    for (auto city : cities) {
        deque<string>::iterator it = cache.begin();
        bool find = false;
        for (; it != cache.end(); it++) {
            if (toLow(*it) == toLow(city)) {
                cache.erase(it);
                cache.push_front(city);
                time++;
                find = true;
                break;
            }
        }
        if (!find) {
            if (cache.size() >= cacheSize && cacheSize > 0) {
                cache.pop_back();
            }
            if (cacheSize > 0) cache.push_front(city);
            time += 5;
        }
    }
    return time;
}
