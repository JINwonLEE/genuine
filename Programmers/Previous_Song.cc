#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<string>> info;

int makeTime(string st, string en) {
    if (st[0] == en[0] && st[1] == en[1]) {
        string st_tmp = st.substr(3, 2);
        string en_tmp = en.substr(3, 2);
        return stoi(en_tmp) - stoi(st_tmp);
    }
    int st_h = stoi(st.substr(0, 2));
    int en_h = stoi(en.substr(0, 2));
    int st_tmp = stoi(st.substr(3, 2));
    int en_tmp = stoi(en.substr(3, 2));
    int dur = 0;
    if (st_tmp > en_tmp) {
        en_h--;
        dur += en_tmp + 60 - st_tmp;
    } else {
        dur += en_tmp - st_tmp;
    }
    dur += (en_h - st_h) * 60;
    return dur;
}

void preProcess(vector<string>& mus) {
    for (auto ele : mus) {
        stringstream str(ele);
        string tmp;
        vector<string> raw;
        
        while (getline(str, tmp, ',')) {
            raw.push_back(tmp);
        }
        int duration = makeTime(raw[0], raw[1]);
        string mel = "";
        int count = 0;
        int index = 0;
        while (count < duration) {
            string m = "";
            m += raw[3][index];
            tmp = raw[3].substr(index, 2);
            if (tmp == "C#" || tmp == "D#" || tmp == "F#" || tmp == "G#" || tmp == "A#") {
                m = tolower(m[0]);
                index = (index + 1) % raw[3].size();
            }
            mel += m;
            index = (index + 1) % raw[3].size();
            count++;
        }
        
        info.push_back({raw[2], mel, to_string(duration)});
    }
}

bool checkString(string m, string mel) {
    auto pos = mel.find(m, 0);
    while (pos != string::npos) {
        return true;
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int duration = 0;
    preProcess(musicinfos);
    string mel = "";
    int count = 0;
    int index = 0;
    while (index < m.size()) {
        string tmp = "";
        tmp += m[index];
        string tmp2 = m.substr(index, 2);
        if (tmp2 == "C#" || tmp2 == "D#" || tmp2 == "F#" || tmp2 == "G#" || tmp2 == "A#") {
                tmp = tolower(tmp[0]);
                index = index + 1;
        }
        mel += tmp;
        index = index + 1;
    }
    m = mel;
    
    for (int i = 0; i < info.size(); i++) {
        if (info[i][1].find(m) != string::npos) {
            bool isValid = true;
            isValid = checkString(m, info[i][1]);
            if (!isValid) continue;
            if (duration < stoi(info[i][2])) {
                answer = info[i][0];
                duration = stoi(info[i][2]);
            }
        }
    }
    
    return answer;
}
