#include <iostream>
using namespace std;
void solve(int* arr, int* dy, int N);
int main(){
	int Case;
	cin >> Case;
	while(Case--){
		int num;
		cin >> num;
		int res = 0;
		int *array = new int[num];
		int *lis = new int[num];
		for(int i = 0 ; i < num; i++){
			cin >> array[i];
		}
		solve(array, lis, num);
		for(int i = 0; i< num; i++){
			if(res < lis[i])
				res = lis[i];
		}
		cout << res << endl;
	}
	return 0;
}

void solve(int* arr, int* dy, int N){
	for(int i = 0; i < N; i++){
		dy[i] = 1;
		for(int k = 0; k < i; k++){
			if(arr[k] < arr[i] && dy[i] < dy[k] + 1) // �տ� �ִ� ���� �� ���������� ũ�� ���� �ڱ� ���� ���� �迭 ã 
				dy[i] = dy[k] +1;
		}
	}
}

