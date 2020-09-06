#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;
bool comp(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> gen_to_index;
    vector<vector<int>> ordered_songs(100, vector<int>(2, -1));
    int index = 0;
    int len = genres.size();
    
    for (int i = 0; i < len; i++) {
        if (gen_to_index.find(genres[i]) == gen_to_index.end()) {
            gen_to_index[genres[i]] = 0;
        }
        gen_to_index[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> tmp_vector;
    for (auto& it : gen_to_index) tmp_vector.push_back(it);
    
    sort(tmp_vector.begin(), tmp_vector.end(), comp);
    
    for (auto& A : tmp_vector) {
        gen_to_index[A.first] = index++;
    }
    
    for (int i = 0; i < len; i++) {
        int ind = gen_to_index[genres[i]];
        if (plays[i] > plays[ordered_songs[ind][0]]) {
            ordered_songs[ind][1] = ordered_songs[ind][0];
            ordered_songs[ind][0] = i;
        } else if (plays[i] == plays[ordered_songs[ind][0]]) {
            if (plays[i] > plays[ordered_songs[ind][1]]) {
                ordered_songs[ind][1] = i;
            }
        } else if (plays[i] > plays[ordered_songs[ind][1]]) {
            ordered_songs[ind][1] = i;
        }
    }
    index = 0;
    while (ordered_songs[index][0] != -1) {
        for (int i = 0; i < 2; i++) {
            if (ordered_songs[index][i] != -1) {
                answer.push_back(ordered_songs[index][i]);
            }
        }       
        index++;
    }        
    return answer;
}
