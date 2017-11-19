#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int Case;
	cin >> Case;
	int c = 1;
	while(Case--){
		int bound;
		cin >> bound;
		int num[9];
		int sum = 0;
		for(int i = 0; i< 9; i++){
			cin >> num[i];
			sum += num[i];
		}
		if(sum <= bound)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
