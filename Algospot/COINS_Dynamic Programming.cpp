#include <iostream>
using namespace std;

int *array;
int diverse;

int main(){
	int Case;
	cin >> Case;
	while(Case--){
		int Price;
		cin >> Price;
		cin >> diverse;
		long long count = 0;
		array = new int[diverse];
		for(int i = 0; i< diverse; i++)
			cin >> array[i];                   ///√ ±‚»≠
		long long *Ncoin = new long long[5005];
		for(int i = 0; i< 5005; i++)
			Ncoin[i] = 0;
		for(int i = 0; i < diverse; i++){
			int coin = array[i];
			if(coin > Price)
				continue;
			Ncoin[coin]++;
			for(int j =1; j+ coin <= Price; j++)
				Ncoin[coin+j] += Ncoin[j];
		}
		count = Ncoin[Price];
		if(count > 1000000007)
			cout << count % 1000000007 <<endl;
		else
			cout << count << endl;
		delete [] array;
		delete [] Ncoin;
	}
	return 0;
}



