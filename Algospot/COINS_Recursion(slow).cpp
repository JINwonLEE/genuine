#include <iostream>
using namespace std;

int *array;
int diverse;
int solve(int ind, int Price);

int main(){
	int Case;
	cin >> Case;
	while(Case--){
		int Price;
		cin >> Price;
		cin >> diverse;
		int count = 0;
		array = new int[diverse];
		for(int i = 0; i< diverse; i++)
			cin >> array[i];                   ///ÃÊ±âÈ­
		count = solve(0, Price);
		if(count > 1000000007)
			count = count % 1000000007;
		cout << count << endl;
		delete [] array;
	}
	return 0;
}

int solve(int ind, int Price){
	int cnt;
	cnt = 0; 
	if(array[ind] == Price || Price == 0)
		return 1;
	if(ind == diverse-1 && Price < array[ind])
		return 0;

	if(array[ind] < Price && array[ind+1] > Price){
		Price -= array[ind];
		cnt += solve(ind, Price);
	}
	if(array[ind+1] <= Price){
		while(Price >= array[ind+1]){
			cnt += solve(ind+1, Price);
			Price -= array[ind];
		}
		if(Price >= array[ind])
				cnt += solve(ind, Price);
	}
	return cnt;
}
