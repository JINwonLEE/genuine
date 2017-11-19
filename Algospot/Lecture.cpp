#include <iostream>
#include <string>
using namespace std;

int main() {
	int Test;
	cin >> Test;
	while(Test--){
		string arr;
		cin >> arr;
		string *sp = new string[arr.length()/2];
		int k = 0;
		for(int i = 0 ; i < arr.length(); i++){
			sp[k] += arr[i];
			i++;
			sp[k] += arr[i];
			k++;
		}
		
		for(int i = 0; i< k; i++){
			for(int j = 0; j < k; j++){
				if(sp[i].compare(sp[j])<0){
					string temp = sp[i];
					sp[i] = sp[j];
					sp[j] = temp;
				}
			}
		}
		for(int i = 0; i < k; i++)
			cout << sp[i];
		
		cout << endl;
	}
	return 0;
}
