#include <iostream>
#include <cmath>
using namespace std;

int n;
double **cost; // distance
double **weight; // memoization    memoization bit���� 0�� ���� �湮�Ѱ�, �ƴ� ���� �湮 ���� �� 
int b;

double tsp(int start, int to, int size);
void solve();
double finding();
int findind(int to);



double tsp(int start, int to, int size){

	if(weight[start][to] > 0)
		return weight[start][to];				// �̹� ���� ������ �׳� ����  

	if(size ==1){
		int last = findind(to);
		return cost[start][last];
	}
	
	double m = 15000.0;
	for(int i = 0; i< n; i++){
		if(!(to & (1 << i))) continue;
		double v;
		 v = tsp(i, to & (~(1<<i) & b) , size -1) + cost[start][i];   
		m = min(m, v);

	}
	weight[start][to] = m;
	return m;
	
}

int findind(int t){
	int i;
	for( i = 0; i < n; i++){
		if((1<<i) & t)	break;
	}
	return i;
}


void solve(){
	cin >> n;
	b =  pow(2, n) - 1;
	cost = new double*[n];
	weight = new double*[n];
	for(int i = 0; i < n; i++){
		cost[i] = new double[n];
		weight[i] = new double[1<<n];
	}								//cost, weight �޸� �Ҵ� 
	for(int i = 0; i < n; i++){
		for(int j =0; j < n; j++){
			cin >> cost[i][j];
		}
		for(int j = 0; j < 1<<n; j++)
			weight[i][j] = 0.0;
		
	}								// cost �� ��ǲ��� 

	cout.precision(10);
	double minimum = finding();
	cout << fixed << minimum << endl;
	
	delete [] cost;
	delete [] weight;
}

double finding(){
	double m = 15000.0;
	for(int i = 0; i < n; i++){
		double v = tsp(i, ~(1<<i) & b, n-1) + cost[i][i];		//tsp(������, �湮�� ��, ��� �湮�� ���� ���Ҵ���) 
		m = min(m, v);
	}
	
	return m;
}

int main(){
	int Case;
	cin >> Case;
	while(Case--){
		solve();	//case ��ǲ�� �ް� solve�� 
	}
	return 0;
}

