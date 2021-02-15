#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct item {
    string file;
    string head;
    string number;
};

vector<item> items;

bool cmp(const item& a, const item& b) {
    if (a.head < b.head) {
        return true;
    } else if (a.head == b.head) {
        return stoi(a.number) < stoi(b.number);
    }
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for (auto f : files) {
        item it;
        it.file = f;
        string tmp_h = "";
        int num_index = 0;
        string tmp_num = "";
        for (int i = 0; i < f.size(); i++) {
            if (f[i] >= '0' && f[i] <= '9') {
                num_index = i;
                transform(tmp_h.begin(), tmp_h.end(), tmp_h.begin(), ::tolower);
                it.head = tmp_h;
                break;
            } else {
                tmp_h += f[i];    
            }
        }
        for (; num_index < f.size(); num_index++) {
            if (!(f[num_index] >= '0' && f[num_index] <= '9')) {           
                break;
            } else {
                tmp_num += f[num_index];
            }
        }
        it.number = tmp_num;
        items.push_back(it);
    }
    
    stable_sort(items.begin(), items.end(), cmp);
    for (auto ele : items) {
        answer.push_back(ele.file);
    }
    return answer;
}
