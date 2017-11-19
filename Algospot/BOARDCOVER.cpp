#include <iostream>
using namespace std;

int H, W; 
char** map;

int find(char** map, int anum);

int find(char** map, int anum){
	int X;
	int Y;
	
	for(int i = 0; i< H; i++){
		for(int j = 0; j < W; j++){
			if(map[i][j] == '.'){
				X = i;
				Y = j;
				i = H-1;
				j = W-1;
				
			}
		}
	} // finding first .
	bool p1 = false;
	bool p2 = false;
	bool p3 = false;
	bool p4 = false;
	if((X+1 < H) && (Y+1 < W) && (X>= 0) && (Y>= 0))
		if((map[X][Y+1] == '.') && (map[X+1][Y+1] == '.')) p1 = true; // ㄱ 
	if((X+1 < H) && (Y+1 <W) && (X>=0) && (Y>=0))
		if((map[X][Y+1] == '.') && (map[X+1][Y] == '.')) p2 = true; // ㄱ 거꾸로 
	if((X +1 < H) && (Y+1 < W) && (X>=0) && (Y>=0))
		if((map[X+1][Y] == '.') && (map[X+1][Y+1] == '.')) p3 = true; // ㄴ 
	if((X+1 < H) && (Y-1 >= 0) && (X>= 0) && (Y < W))
		if((map[X+1][Y] == '.') && (map[X+1][Y-1] == '.')) p4 = true; // ㄴ 거꾸로
	if(anum == 3){
		if(p1||p2||p3||p4){
			return 1;
		}
		else
			return 0;
	}
	int count = 0;
	if(p1){
		map[X][Y] = '#';
		map[X][Y+1] = '#';
		map[X+1][Y+1] = '#';
		anum -= 3;
		count += find(map, anum);
		map[X][Y] = '.';
		map[X][Y+1] = '.';
		map[X+1][Y+1] = '.';
		anum += 3;
	} 
	if(p2){
		map[X][Y] = '#';
		map[X+1][Y] = '#';
		map[X][Y+1] = '#';
		anum -= 3;
		count += find(map, anum);
		map[X][Y] = '.';
		map[X+1][Y] = '.';
		map[X][Y+1] = '.';
		anum += 3;
	} 	
	if(p3){
		map[X][Y] = '#';
		map[X+1][Y] = '#';
		map[X+1][Y+1] = '#';
		anum -= 3;
		count += find(map, anum);
		map[X][Y] = '.';
		map[X+1][Y] = '.';
		map[X+1][Y+1] = '.';
		anum += 3;
	} 
	if(p4){
		map[X][Y] = '#';
		map[X+1][Y] = '#';
		map[X+1][Y-1] = '#';
		anum -= 3;
		count += find(map, anum);
		map[X][Y] = '.';
		map[X+1][Y] = '.';
		map[X+1][Y-1] = '.';
		anum += 3;
	} 
	return count;
}

int main(){
	int Case;
	cin >> Case;
	while(Case--){
	cin >> H;
	cin >> W;
	map = new char*[H];
	for(int i = 0; i < H; i++){
		map[i] = new char[W];
	}
	int anum = 0;
	for(int i = 0; i< H; i++){
		for( int j = 0; j < W; j++){
			cin >> map[i][j];
			if(map[i][j] == '.'){
				anum++;                   // anum 증가 
			}
		}
	}
	int cNum = 0; 
	if(anum == 0){
		cNum= 1;
	}
	else if(anum % 3 != 0){
		cNum= 0;
	}
	else{
		cNum = find(map, anum);
	}
	cout << cNum << endl;
	
	for(int i = 0 ; i< H; i++){
		delete [] map[i];
	}
	delete [] map;
	
	}
	return 0;
}
