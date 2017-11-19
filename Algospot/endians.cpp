#include <iostream>
using namespace std;

int main(){
	int Case;
	cin >> Case;
	
	while(Case--){
		unsigned int a;
		cin >> a;
		
		cout << ((a&0xff)<<24)+ ((a&0xff00)<<8) + ((a&0xff0000)>>8) + ((a&0xff000000)>>24) << endl;
	}
}
