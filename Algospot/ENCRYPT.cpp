#include <iostream>
using namespace std;

int main(){
	int Case;
	cin >> Case;
	
	while(Case--){
		string arr;
		cin >> arr;
		for(int i = 0; i<arr.length();i+=2){
			cout << arr[i];
		}
		for(int i = 1; i<arr.length();i+=2){
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}