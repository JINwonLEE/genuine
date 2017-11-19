#include <iostream>
using namespace std;

int main(){
	int Case;
	cin >> Case;
	while(Case--){
		int mid;
		cin >> mid;
		int *length = new int[2*mid-1];
		int** dia = new int*[2*mid -1];
		int** cost = new int*[2*mid-1];
		
		for(int i = 0; i< mid-1; i++){
			dia[i] = new int[i+1];
			dia[2*mid-2-i] = new int[i+1];
			cost[i] = new int[i+1];
			cost[2*mid-2-i] = new int[i+1];
			length[i] = i+1;
			length[2*mid-2-i] = i+1;
		}
		cost[mid-1] = new int[mid];
		length[mid-1] = mid;
		dia[mid-1] = new int[mid];				//초기화 
		for(int i = 0; i < 2*mid-1; i++){
			for(int j = 0; j < length[i]; j++){
				cin >> dia[i][j];
				cost[i][j] = 0;
			}
		}
		// input 
		cost[0][0] = dia[0][0];
		for(int i = 0; i < mid-1; i++){
			int l = 0; 	
			while( l < length[i]){	
				if(cost[i+1][l] == 0)
					cost[i+1][l] = cost[i][l] + dia[i+1][l];
				else{
					if(cost[i+1][l] < cost[i][l] + dia[i+1][l])
						cost[i+1][l] = cost[i][l] + dia[i+1][l];
				}
				if(cost[i+1][l+1] == 0 && l+1 <= length[i])
					cost[i+1][l+1] = cost[i][l]+ dia[i+1][l+1];
				else if(l+1 <= length[i]){
					if(cost[i+1][l+1] < cost[i][l] + dia[i+1][l+1])
						cost[i+1][l+1] = cost[i][l]+ dia[i+1][l+1];
				}
				l++;
			}
		}																	// 커지는 다이아몬드 부분 
		for(int i = mid-1; i < 2*mid -2; i++){
			int l = 0; 	
			while( l < length[i]){	
				if(cost[i+1][l] == 0)
					cost[i+1][l] = cost[i][l] + dia[i+1][l];
				else{
					if(cost[i+1][l] < cost[i][l] + dia[i+1][l])
						cost[i+1][l] = cost[i][l] + dia[i+1][l];
				}
				if(cost[i+1][l-1] == 0 && l-1 >=0)
					cost[i+1][l-1] = cost[i][l]+ dia[i+1][l-1];
				else if(l-1>=0){
					if(cost[i+1][l-1] < cost[i][l] + dia[i+1][l-1])
						cost[i+1][l-1] = cost[i][l]+ dia[i+1][l-1];
				}
				l++;
			}
		}																	// 작아지는 다이아몬드 부분 
		cout << cost[2*mid-2][0] <<endl;
	}
	return 0;
}
