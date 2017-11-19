#include <iostream>
using namespace std;

int main(){
	int Case;
	cin >> Case;
	string arr[11];
	arr[0] = "zero";
	arr[1] = "one";
	arr[2] = "two";
	arr[3] = "three";
	arr[4] = "four";
	arr[5] = "five";
	arr[6] = "six";
	arr[7] = "seven";
	arr[8] = "eight";
	arr[9] = "nine";
	arr[10] = "ten";
	
	while(Case--){
		char A[6];
		char operation;
		char B[6];
		string cor;
		char result[11];
		cin >> A;
		cin >> operation;
		cin >> B;
		cin >> cor;
		cin >> result;
		int a;
		int b;
		int re;
		string op_result;
		for(int i = 0; i< 11; i++){
			if(A == arr[i])
				a = i;
			if(B == arr[i])
				b = i;	
		}
		
		switch(operation){
			case '+':
				re = a+b;
				break;
			case '-':
				re = a-b;
				break;
			case '*':
				re = a*b;
				break;
		}
		bool check = false;
		
		for(int i = 0; i< 11; i++){
			if(re == i){
				op_result = arr[i];
				check = true;
			}
		}
		int spell = 0;
		if(!check)
			cout << "No" << endl;
		else{
			int k = 0;
			while(k < op_result.length()){
				for(int l = 0; l < 10; l++){
					if(op_result[k] == result[l]){
						op_result[k] = ' ';
						spell++;
						break;
					}	
				}
				k++;
			}
		
			if(spell == op_result.length())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	
	return 0;
}
