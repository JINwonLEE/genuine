#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int Case;
	cin >> Case;
	int c = 1;
	while(Case--){
		string arr;
		float num;
		cin >> num;
		cin >> arr;
		cout << c << " ";
		cout.precision(4);
		cout << fixed;
		if(arr == "l")
			cout<< num * 0.2642 << " g";
		else if(arr =="g")
			cout << num * 3.7854 << " l";
		else if(arr =="kg")
			cout << num * 2.2046 << " lb";
		else if(arr == "lb")
			cout << num * 0.4536 << " kg";
		cout << endl;
		c++;
	}
	return 0;
}