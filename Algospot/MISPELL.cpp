#include <iostream>
using namespace std;

int main(){
	int Case;
	cin >> Case;
	int c = 1;
	while(Case--){
		string arr;
		int num;
		cin >> num;
		cin >> arr;
		cout << c << " ";
		for(int i = 0; i< arr.length(); i++){
			if(i != num-1)
				cout << arr[i];
			else
				continue;
		}
		cout << endl;
		c++;
	}
	return 0;
}
