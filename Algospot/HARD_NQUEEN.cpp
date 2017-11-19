#include <iostream>
#include <cmath>
using namespace std;

bool solve(int p);

int ans;
int *queen;
int n;

int main(){
	int Case;
	cin >> Case;
	while(Case--){
		cin >> n;
		queen = new int[n];
		ans = 0;
		solve(0);
		cout << ans << endl;
	}
	return 0;
}

bool solve(int p){
	if(p == n){
		ans++;
		return true;
	}
	for(int i = 0; i < n; i++){
		int ava = 1;
		for(int j = 0; j < p; j++){
			if(queen[j] == i || abs(p- j) == abs(queen[j]-i))
				ava = 0;
		}
		if(ava){
			queen[p] = i;
			solve(p+1);
		}
	}
}
