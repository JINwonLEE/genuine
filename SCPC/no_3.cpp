#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

vector<pair<int, int> > edge;
typedef struct st_end {
    int st;
    int end;
}st_end;
st_end edge_start_end[200001];
bool erase[200001];
typedef struct edge_size{
    int v;
    int e_size;
    int score;
}edge_size;

edge_size ed_size[200001];
bool my_compare(pair<int, int> a, pair<int, int> b) { if (a.first == b.first) return ed_size[a.second].score > ed_size[b.second].score; return a.first < b.first;}
bool ed_compare2(edge_size a, edge_size b) {if (a.e_size == b.e_size) return a.score > b.score; return a.e_size < b.e_size;}

bool is_valid_to_erase(int v) {
    int st = edge_start_end[v].st;
    int end = edge_start_end[v].end;
    int ne[2] = {0, 0}; 
    int ind = 0;
    for (int i = st; i <= end; i++) {
        if (!erase[edge[i].second]) {
            if (ind >= 2) {
                return false;
            }
            else {
                ne[ind] = edge[i].second;
                ind++;
            }
        }
    }
    
    if (ind == 1) {
        return false;
    }

    for (int i = edge_start_end[ne[0]].st; i <= edge_start_end[ne[0]].end; i++) {
        if (edge[i].second == ne[1]) {
            return true;
        }
    }

    return false;
}

int main(int argc, char** argv)
{
	int T, test_case, Answer;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;

        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N ; i++) {
            edge_start_end[i].st = -1;
            edge_start_end[i].end = -1;
            erase[i] = false;
            ed_size[i].e_size = 0;
            ed_size[i].v = i;
            ed_size[i].score = 0;
        }

        for (int i = 0 ; i < M ; i++) {
            int start, end;
            cin >> start >> end;
            ed_size[start].e_size++;
            ed_size[end].e_size++;
            edge.push_back(make_pair(start, end));
            edge.push_back(make_pair(end, start));
        }
        for (int i = 0; i < edge.size(); i++) {
            ed_size[edge[i].first].score += ed_size[edge[i].second].e_size;
        }

        sort(edge.begin(), edge.end(), my_compare);

        for (int i = 0; i < edge.size(); i++) {
            if (edge_start_end[edge[i].first].st == -1) {
                edge_start_end[edge[i].first].st = i;
                if (i != 0) {
                    edge_start_end[edge[i-1].first].end = i-1;
                }
            }
            if (i == edge.size() - 1) {
                edge_start_end[edge[i].first].end = i;
            }

        }
        sort(ed_size, ed_size + N + 1, ed_compare2);
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (is_valid_to_erase(ed_size[i].v) && !erase[ed_size[i].v]) {
                erase[ed_size[i].v] = true;
                count++;
            }
            if (N - count == 2) {
                break;
            }
        }
        Answer = N - count;
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;

        edge.clear();
	}

	return 0;//Your program should return 0 on normal termination.
}
