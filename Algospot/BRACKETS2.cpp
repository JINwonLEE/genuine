#include <iostream>
#include <string>
using namespace std;
class Stack{
	private:
		char brack[10000];
		int top;

	public:
		int mnum;
		bool used;
		Stack(){
			for(int i = 0; i < 10000; i++){
				brack[i] = '0';	
			}
			top = 0;
			used = false;
			mnum = 0;
		}
		
		void push(char bracket){
			brack[top] = bracket;
			top++;
		}
		void pop(){
			if(!isEmpty()){
				top--;
				brack[top] = '0';
			}
		}
		char Top(){
			char tmp = brack[top-1];
			return tmp;
		}
		bool isEmpty(){
			if(top == 0)
				return true;
			else
				return false;
		}
		void isUsed(){
			used = true;
		}
		~Stack(){
			
		}
};




int main(){
	int Case;
	cin >> Case;
	while(Case--){
		Stack brackets;
		string tmp;
		cin >> tmp;
		for(int i = 0 ; i < tmp.length();i++){
			if(tmp[i] == '[' || tmp[i] == '{' || tmp[i] == '('){
				brackets.isUsed();
				brackets.push(tmp[i]);
				brackets.mnum++;
			}
			if(tmp[i] == ']'){
				brackets.mnum--;
				char bra = brackets.Top();
				if(bra == '['){
					brackets.pop();				
				}
			}		
			else if(tmp[i] == '}'){
				brackets.mnum--;
				char bra = brackets.Top();
				if(bra == '{'){
					brackets.pop();
				}
			}		
			else if(tmp[i] == ')'){
				brackets.mnum--;
				char bra = brackets.Top();
				if(bra == '('){
					brackets.pop();
				}
			}		
		}
		if(brackets.isEmpty() && brackets.used == true && brackets.mnum == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
