#include <iostream>
using namespace std;

struct point {
	int x;
	int y;
};

int main(){
	int Case;
	cin >> Case;
	
	while(Case--){
		point p[4];
		cin >> p[0].x;
		cin >> p[0].y;
		cin >> p[1].x;
		cin >> p[1].y;
		cin >> p[2].x;
		cin >> p[2].y;
		int sumx, sumy;
		
		for(int i= 0; i<3; i++){
			for(int j = 0; j < 3; j++){
				if(p[i].x != p[j].x && p[i].y != p[j].y && p[i].x != 0 && p[j].x != 0){
					sumx = p[i].x+p[j].x;
					sumy = p[i].y+p[j].y;
					p[i].x = 0;
					p[j].x = 0;
					
				}
			}
		}
		
		for(int i = 0; i<3; i++){
			if(p[i].x != 0){
				p[3].x = sumx-p[i].x;
				p[3].y = sumy-p[i].y;
			}
		}
		
		cout << p[3].x <<" "<< p[3].y << endl;
	}
	return 0;	
}
