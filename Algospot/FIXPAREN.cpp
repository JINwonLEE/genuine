#include <iostream>
#include <string>

using namespace std;
struct item{
	char x;
	int y;
};

class Stack{
	private:
		item brack[100];
		int top;

	public:
		Stack(){
			for(int i = 0; i < 100; i++){
				brack[i].x = '0';
				brack[i].y = -1;	
			}
			top = 0;
		}
		
		void push(char bracket, int ind){
			brack[top].x = bracket;
			brack[top].y = ind;
			top++;
		}
		void pop(){
			if(!isEmpty()){
				top--;
				brack[top].x = '0';
				brack[top].y = -1;
			}
		}
		item Top(){
			return brack[top-1];
		}
		bool isEmpty(){
			if(top == 0)
				return true;
			else
				return false;
		}
		~Stack(){
			
		}
};

int main(){
	Stack arr;
	int Case;
	cin >>Case;
	
	while(Case--){
		string ch;
		cin >> ch;
		string pri;
		cin>> pri;
		int i = 0;
		int b = 0;
		int wb = 0;
		char pri2[4];
		for(int j = 0; j < 4; j++){
			if(pri[j] == '[')
				pri2[j] = ']';
			else if(pri[j] == '{')
				pri2[j] = '}';
			else if(pri[j] == '<')
				pri2[j] = '>';
			else if(pri[j] == '(')
				pri2[j] = ')';
		}
		while(i < ch.length()){
			if(ch[i] == '[' || ch[i] == '{' || ch[i] == '(' || ch[i] == '<')
				arr.push(ch[i], i);
			if(ch[i] == ']'){
				item brac = arr.Top();
				if(brac.x != '['){
					for(int j = 0; j <4; j++){
						if(pri[j] == '[')
							b = j;
						else if(pri[j] == brac.x)
							wb = j;
					}
					if(b < wb)
						ch[brac.y] = '[';
					else
						ch[i] = pri2[wb];
				}
				arr.pop();
			}	
			else if(ch[i] == '>'){
				item brac = arr.Top();
				if(brac.x != '<'){
					for(int j = 0; j <4; j++){
						if(pri[j] == '<')
							b = j;
						else if(pri[j] == brac.x)
							wb = j;
					}
					if(b < wb)
						ch[brac.y] = '<';
					else
						ch[i] = pri2[wb];
				}
				arr.pop();
			}
			else if(ch[i] == '}'){
				item brac = arr.Top();
			
				if(brac.x != '{'){
					for(int j = 0; j <4; j++){
						if(pri[j] == '{')
							b = j;
						else if(pri[j] == brac.x)
							wb = j;
					}
					if(b < wb)
						ch[brac.y] = '{';
					else
						ch[i] = pri2[wb];
				}
				arr.pop();
			}
			else if(ch[i] == ')'){
					item brac = arr.Top();
				if(brac.x != '('){
					for(int j = 0; j <4; j++){
						if(pri[j] == '(')
							b = j;
						else if(pri[j] == brac.x)
							wb = j;
					}
					if(b < wb)
						ch[brac.y] = '(';
					else
						ch[i] = pri2[wb];
				}
				arr.pop();
			}
			i++;		
		}
		cout << ch << endl;
	}
	return 0;
}
