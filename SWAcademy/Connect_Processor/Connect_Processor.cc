#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int max_core = 0;
int min_cost = 0;

void connectProcessor(vector<vector<int> >& m, vector<pair<int, int> > cores, int index, int dir, int num_core, int cost) {
	if (index == cores.size()) {
		if (num_core > max_core) {
			max_core = num_core;
			min_cost = cost;
		} else if (num_core == max_core) {
			if (min_cost > cost) {
				min_cost = cost;
			}
		}
		return;
	}

	//cout << "Enter index : " << index << ", dir : " << dir << ", num core : " << num_core << ", cost : " << cost << endl;
	bool isValid = true;
	int connect_cost = 0;
	if (dir == 0) { // up
		for (int i = cores[index].first - 1; i >= 0; i--) {
			if (m[i][cores[index].second] != 0) {
				isValid = false;
			}
		}
		if (isValid) {
			connect_cost += cores[index].first;
			for (int i = cores[index].first - 1; i >= 0; i--) {
				m[i][cores[index].second] = 2;
			}
		}
	} else if (dir == 1) { // down
		for (int i = cores[index].first + 1; i < m.size(); i++) {
			if (m[i][cores[index].second] != 0) {
				isValid = false;
			}
		}
		if (isValid) {
			connect_cost += m.size() - cores[index].first - 1;
			for (int i = cores[index].first + 1; i < m.size(); i++) {
				m[i][cores[index].second] = 2;
			}
		}
	} else if (dir == 2) { // left
		for (int i = cores[index].second - 1; i >= 0; i--) {
			if (m[cores[index].first][i] != 0) { 
				isValid = false;
			}
		}
		if (isValid) {
			connect_cost += cores[index].second;
			for (int i = cores[index].second - 1; i >= 0; i--) {
				m[cores[index].first][i] = 2;
			}
		}
		
	} else { // right
		for (int i = cores[index].second + 1; i < m[0].size(); i++) {
			if (m[cores[index].first][i] != 0) { 
				isValid = false;
			}
		}
		if (isValid) {
			connect_cost += m.size() - cores[index].second - 1;
			for (int i = cores[index].second + 1; i < m[0].size(); i++) {
				m[cores[index].first][i] = 2;
			}
		}
	}

	if (num_core + isValid + cores.size() - index - 1 < max_core) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		connectProcessor(m, cores, index + 1, i, num_core + isValid, connect_cost + cost);	
	}

	if (isValid) {
		if (dir == 0) { // up
			for (int i = cores[index].first - 1; i >= 0; i--) {
				m[i][cores[index].second] = 0;
			}
		} else if (dir == 1) { // down
			for (int i = cores[index].first + 1; i < m.size(); i++) {
				m[i][cores[index].second] = 0;
			}
		} else if (dir == 2) { // left
			for (int i = cores[index].second - 1; i >= 0; i--) {
				m[cores[index].first][i] = 0;
			}
		} else { // right
			for (int i = cores[index].second + 1; i < m[0].size(); i++) {
				m[cores[index].first][i] = 0;
			}
		}
	}
	

}

void solve() {
	int N;
	cin >> N;

	min_cost = 0;
	max_core = 0;

	vector<vector<int> > m(N, vector<int>(N, 0));
	vector<pair<int, int> > cores;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];

			if (i != 0 && j != 0 && m[i][j] == 1) {
				cores.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		connectProcessor(m, cores, 0, i, 0, 0);
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		solve();
		cout << "#" << i + 1 << " " << min_cost << endl;
	}
	return 0;
}
