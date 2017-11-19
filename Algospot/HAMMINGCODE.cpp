#include <iostream>
using namespace std;
int XOR(int a, int b);

int main(){
	int Case;
	cin >> Case;
	
	while(Case--){
		string num;
		cin >> num;
		int check[3];
		int ind;
		check[0] = XOR(XOR(num[0], num[2]), XOR(num[4], num[6]));
		check[1] = XOR(XOR(num[1], num[2]), XOR(num[5], num[6]));
		check[2] = XOR(XOR(num[3], num[4]), XOR(num[5], num[6]));
		ind = check[0]+check[1]*2 + check[2]*4;
	
		if(ind == 0){
			cout << num[2] << num[4] << num[5] << num[6] << endl;
		}
		else{
			if(num[ind-1] == '1')
				num[ind-1] = '0';
			else if(num[ind-1] == '0')
				num[ind-1] = '1';
			cout << num[2] << num[4] << num[5] << num[6] << endl;
		}
	}
	return 0;
}

int XOR(int a, int b){
	return (a + b) % 2;
}
