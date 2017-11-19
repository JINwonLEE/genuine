#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int Case;
	cin >> Case;
	while(Case--){
		int num;
		int sum = 0;
		cin >> num;
		int *arr = new int[num];
		for(int i = 0; i< num; i++)
			arr[i] = 0;
		int k = 0;
		for(int i = 1; i < num; i++){
			if(num%i == 0){
				arr[k] = i;
				sum += i;
				k++;
			}
		}
		if(sum > num){
			for(int i = k-1; i>=0; i--){
				if(num >= arr[i])
					num -=arr[i];
				if(num == 0)
					break;
			}
		}
		if(num == 0 || num >= sum)
			cout << "not weird" <<endl;
		else
			cout << "weird" << endl;
		delete [] arr;
	}
	return 0;
}
