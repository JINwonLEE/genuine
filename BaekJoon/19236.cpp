#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct Fish {
	int id;
	int dir;
	int cur_pos_x;
	int cur_pos_y;
};

struct Shark {
	int dir;
	int cur_pos_x;
	int cur_pos_y;
	int count;
};


pair<int,int> direction_map[9] = {{0, 0}/* dummy */, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}}; // y, x  

int getDirection(int cur_x, int cur_y, int dir, const vector<vector<int>>& map) {
    int cur = dir;
	do {
        int x, y;
		tie(y, x) = direction_map[cur];
		if ( cur_y + y >= 4 || cur_y + y < 0 || cur_x + x >= 4 
				|| cur_x + x < 0 || map[cur_y + y][cur_x + x] == -1) {
			cur = (cur + 1) % 9 != 0 ? (cur + 1) % 9 : 1;
		} else {
			return cur;
		}
	} while (cur != dir);
	return -1;
}

void swapFish(Fish& a, Fish& b, vector<vector<int>>& map) {
	Fish tmp;
	tmp.cur_pos_x = a.cur_pos_x;
	tmp.cur_pos_y = a.cur_pos_y;

	a.cur_pos_x = b.cur_pos_x;
	a.cur_pos_y = b.cur_pos_y;

	b.cur_pos_x = tmp.cur_pos_x;
	b.cur_pos_y = tmp.cur_pos_y;

	map[a.cur_pos_y][a.cur_pos_x] = a.id;
	map[b.cur_pos_y][b.cur_pos_x] = b.id;
}

vector<pair<int, int>> getSharkPossible(Shark& shark, const vector<vector<int>>& map) {
	int y, x;
	int cur_y = shark.cur_pos_y;
	int cur_x = shark.cur_pos_x;
	vector<pair<int, int>> result;

	tie(y, x) = direction_map[shark.dir];
	int index = 2;
	while (cur_y + y < 4 && cur_y + y >= 0 && cur_x + x < 4 && cur_x + x >= 0) {
		if (map[cur_y + y][cur_x + x] != -2) {
			result.push_back(make_pair(y, x));
		}
		x += direction_map[shark.dir].second;
		y += direction_map[shark.dir].first;
	}

	return result;
}


int maxCount(Shark& shark, Fish* fishes, vector<vector<int>>& map) {
	// Fish 
	for (int i = 1; i <= 16; i++) {
        if (fishes[i].id == -1) continue;
		int cur_y = fishes[i].cur_pos_y;
		int cur_x = fishes[i].cur_pos_x;
		int new_dir = getDirection(cur_x, cur_y, fishes[i].dir, map);
		if (new_dir != -1) {
			fishes[i].dir = new_dir; 	
			int y = direction_map[fishes[i].dir].first;
			int x = direction_map[fishes[i].dir].second;
			if (map[cur_y + y][cur_x + x] != -2)  
				swapFish(fishes[i], fishes[map[cur_y + y][cur_x + x]], map); 
			else {
				fishes[i].cur_pos_x = cur_x + x; 
				fishes[i].cur_pos_y = cur_y + y; 
				map[cur_y + y][cur_x + x] = i;
				map[cur_y][cur_x] = -2;
			}
		}
	}
	vector<pair<int, int>> possible_position = getSharkPossible(shark, map);

	// Shark
	int max = 0;
    int fish_num = 0;
	for (int i = 0; i < possible_position.size(); i++) {
		Fish tmp_fishes[17];
		Shark tmp_shark;
        vector<vector<int>> tmp_map(map);
		copy(fishes, fishes + 17, tmp_fishes);
		int new_shark_y = shark.cur_pos_y + possible_position[i].first;
		int new_shark_x = shark.cur_pos_x + possible_position[i].second;


		tmp_shark.cur_pos_y = new_shark_y;
		tmp_shark.cur_pos_x = new_shark_x;
		tmp_shark.dir = tmp_fishes[tmp_map[new_shark_y][new_shark_x]].dir;
        
		fish_num = tmp_fishes[tmp_map[new_shark_y][new_shark_x]].id;
		tmp_fishes[tmp_map[new_shark_y][new_shark_x]].id = -1;

		// [TODO] Catch Fish 
		tmp_map[shark.cur_pos_y][shark.cur_pos_x] = -2;
		tmp_map[new_shark_y][new_shark_x] = -1;
		int count = maxCount(tmp_shark, tmp_fishes, tmp_map) + fish_num; 
		if (max < count) {
			max = count;
		}
	}

	return max;
}



int main() {
	Fish fishes[17];
	Shark shark{-1, -1, -1, -1};
	vector<vector<int>> map(4, vector<int>(4, 0)); //map[y][x], -1 = shark, -2 = empty

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int id;
			int dir;
			cin >> id >> dir;
			fishes[id].id = id;
			fishes[id].dir = dir;
			fishes[id].cur_pos_x = j;
			fishes[id].cur_pos_y = 3 - i;
			map[3-i][j] = id;
		}
	}
	
	// Shark Came
    int first_fish = fishes[map[3][0]].id;
	shark.cur_pos_x = 0;
	shark.cur_pos_y = 3;
	shark.dir = fishes[map[3][0]].dir;
	fishes[map[3][0]].cur_pos_x = -1;
	fishes[map[3][0]].cur_pos_y = -1;
	fishes[map[3][0]].id = -1;
	map[3][0] = -1;

	// Round stage
	cout <<  first_fish + maxCount(shark, fishes, map) << endl;
	
	return 0;
}


