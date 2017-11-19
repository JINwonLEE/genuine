#include <iostream>
using namespace std;

int array[16];
int ans;
void Switch(int i);
int main(){
	int Case;
	cin >> Case;
	while(Case--){
		for(int i = 0; i < 16; i++)
			cin >> array[i];
		ans = 0;
			if(array[8] != 12){
				while(array[8] != 12)
					Switch(4);
			}
			if(array[10] != 12){
				while(array[10] != 12)
					Switch(2);
			}
			if(array[6] != 12){
				while(array[6] != 12)
					Switch(3);
			}
			if(array[11] != 12){
				while(array[11] != 12)
					Switch(1);
			}
			if(array[9] != 12){
				while(array[9] != 12)
					Switch(9);
			}
			if(array[7] != 12){
				while(array[7] != 12)
					Switch(7);
			}
			if(array[5] != 12){
				while(array[5] != 12)
					Switch(8);
			}
			if(array[3] != 12){
				while(array[3] != 12)
					Switch(6);
			}
			if(array[14] != 12){
				while(array[14] != 12)
					Switch(5);
			}
			if(array[0] != 12){
				while(array[0] != 12)
					Switch(0);
			}
		
		int check =0;
		for(int k = 0; k < 16; k++){
			if(array[k] != 12){
				cout << "-1" << endl;
				check++;
				break;
			}
		}
		if(!check)
			cout << ans << endl;
	}
	return 0;
}

void Switch(int i){
	ans++;
	if(i == 0){
		array[0] += 3;
		array[1] += 3;
		array[2] += 3;
	}
	else if( i == 1){
		array[3] += 3;
		array[7] += 3;
		array[9] += 3;
		array[11] += 3;
	}
	else if(i == 2){
		array[4] += 3;
		array[10] += 3;
		array[14] += 3;
		array[15] += 3;
	}
	else if(i == 3){
		array[0] += 3;
		array[4] += 3;
		array[5] += 3;
		array[6] += 3;
		array[7] += 3;
	}
	else if(i == 4){
		array[6] += 3;
		array[7] += 3;
		array[8] += 3;
		array[10] += 3;
		array[12] += 3;
	}
	else if(i == 5){
		array[0] += 3;
		array[2] += 3;
		array[14] += 3;
		array[15] += 3;
	}
	else if(i == 6){
		array[3] += 3;
		array[14] += 3;
		array[15] += 3;
	}
	else if(i == 7){
		array[4] += 3;
		array[5] += 3;
		array[7] += 3;
		array[14] += 3;
		array[15] += 3;
	}
	else if(i == 8){
		array[1] += 3;
		array[2] += 3;
		array[3] += 3;
		array[4] += 3;
		array[5] += 3;
	}
	else if(i == 9){
		array[3] += 3;
		array[4] += 3;
		array[5] += 3;
		array[9] += 3;
		array[13] += 3;
	}
	
	for(int j = 0; j < 16; j++){
		if(array[j] > 12)
			array[j] -= 12;
	}	
}
