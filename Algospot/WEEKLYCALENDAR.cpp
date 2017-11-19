#include <iostream>
using namespace std;

int main(){
	int Case;
	cin >> Case;
	
	while(Case--){
		int month[14] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};
		int date;
		int start;
		string day;
		int check = 0;
		int input_month;
		
		cin >> input_month;
		cin >> date;
		cin >> day;
		
		if(day == "Sunday"){
			start = date;
		}
		else if(day == "Monday"){
			start = date -1;
			if(start == 0){
				start = month[input_month-1];
				check++;
			}
		}
		else if(day == "Tuesday"){
			start = date -2;
			if(start <= 0){
				start = month[input_month-1] + start;
				check++;
			}
		}
		else if(day == "Wednesday"){
			start = date -3;
			if(start <= 0){
				start = month[input_month-1] + start;
				check++;	
			}
		}
		else if(day == "Thursday"){
			start = date -4;
			if(start <= 0){
				start = month[input_month-1] + start;
				check++;	
			}
		}
		else if(day == "Friday"){
			start = date -5;
			if(start <= 0){
				start = month[input_month-1] + start;
				check++;	
			}
		}
		else if(day == "Saturday"){
			start = date -6;
			if(start <= 0){
				start = month[input_month-1] + start;
				check++;	
			}
		}
		
		for(int i = 0 ; i < 7; i++){
			if(check > 0 && start >month[input_month-1]){
				cout << start - month[input_month-1];
				start++;
			}
			else if(check == 0 && start > month[input_month]){
				cout << start - month[input_month];
				start++;
			}
			else{
				cout << start;
				start++;
			}
			if(i != 6)
				cout << " ";
		}
		
		cout << endl;
	}
	return 0;
}
