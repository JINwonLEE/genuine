#include <iostream>
#include <string>
using namespace std;
string finding(string b, char k);

int main(){
	int Case;
	cin >> Case;
	char str[100];
	char change[128];
	change['0'] = ' ';
	change['1'] = '!';
	change['4'] = '$';
	change['5'] = '%';
	change['8'] = '(';
	change['9'] = ')';
	change['a'] = '*';
	
	for(int i = 0; i < Case; i++){
		cin >> str;	
		for(int k = 0;str[k] != 0; k++){
			if(str[k] == '%'){
				k+= 2;
				cout << change[str[k]]; 
			}
			else{
				cout << str[k];
			}
		}
		cout << endl;
	}
	return 0;
	
}

