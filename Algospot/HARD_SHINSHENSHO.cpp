#include <iostream>
using namespace std;
struct coordinate{
	int i, j;
};

bool solve(coordinate start, coordinate end, int direction);
int H, W;
coordinate dir[] = {
	{-1, 0}, // left
	{1, 0}, // right
	{0, -1},  //up
	{0, 1} // down
};

int ans;
char dest;
char **arr;
char **tarr;

int main(){
	int Case;
	cin >> Case;
	while(Case--){
		
		cin >> H;
		cin >> W;
		arr = new char*[H];
		for(int i = 0; i< H; i++)
			*(arr+i) = new char[W];
			
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				cin >> arr[i][j];
			}
		}
		tarr = new char*[H];
		for(int i = 0; i< H; i++)
			*(tarr+i) = new char[W];
			
		ans = 0;
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(isalpha(arr[i][j])){
					coordinate c = {i, j};
					dest = arr[i][j];
					for(int i = 0; i < H; i++){
						for(int j = 0; j < W; j++){
							tarr[i][j]= arr[i][j];
						}
					}	
					tarr[i][j] = '.';
					solve(c, c, 0);
					arr[i][j] = '*';
				}
			}
		}
		cout << ans << endl;
	}
		return 0;
}


bool solve(coordinate start, coordinate end, int direction){
	if(direction >= 3) return false;

	if(end.i < 0 || end.i >=H || end.j <0 || end.j>= W)
		return false;

	if(tarr[end.i][end.j] == dest){
		ans++;
		tarr[end.i][end.j] = '*';
		return true;
	}

	if(tarr[end.i][end.j] != '.')
		return false; // hurdle
	
	tarr[end.i][end.j] = '*';

	for(int i = 0; i < 4; i++){
		int ni = end.i+dir[i].i;
		int nj = end.j+dir[i].j;

		coordinate next = {ni, nj};
		int ndir = direction;
		if(start.i != next.i && start.j != next.j){
			ndir++;
		}

		solve(end, next, ndir);
	}

	tarr[end.i][end.j] ='.';
	return false;
}
