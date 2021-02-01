#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> bucket;

vector<int> solution(string msg) {
    vector<int> answer;
    for (int i = 0; i < 26; i++) {
        string tmp = "";
        tmp += char(i + 'A');
        bucket.push_back(tmp);
    }
    
    int index = 0;
    string compare = "";
    int prev_index = -1;
    while (index < msg.size()) {
        compare += msg[index];
        vector<string>::iterator pointer = find(bucket.begin(), bucket.end(), compare);
        if (pointer != bucket.end()) {
            index++;
            prev_index = pointer - bucket.begin() + 1; // check
        } else {
            bucket.push_back(compare);
            compare = msg[index];
            answer.push_back(prev_index);
            prev_index = find(bucket.begin(), bucket.end(), compare) 
                - bucket.begin() + 1;
            index++;
        }
    }
    answer.push_back(prev_index);
    return answer;
}
