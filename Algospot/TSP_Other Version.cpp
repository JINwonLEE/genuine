#include <iostream>
using namespace std;

double result;
void Path(int pind, int to, int N, int* path, double** distance, bool* visited);

void Path(int pind, int to, int N, int* path, double** distance, bool* visited){
	bool check = false; 
	path[pind] = to;
	visited[to] = true;
	
	for(int i = 0; i < N; i++){
		check = visited[i];
		if(!check)
			break;
	}
	if(check){
		double temp = 0.0;
		for(int i = 0; i < N-1; i++){
			temp += distance[path[i]][path[i+1]];
		}
		if(result > temp)
			result = temp;
	}
	for(int i = 0; i < N; i++){
		if(!visited[i]){
			Path(pind +1, i, N, path, distance, visited);
			visited[i] = false;
		}
	}
	
}

int main(){
	int Case;
	cin >> Case;
	while(Case--){
		int n;
		cin >> n;
		int* path;
		bool* visited;
		double** dist;
		path = new int[n];
		visited = new bool[n];
		dist = new double*[n];
		result = 150000;
		for(int i = 0 ;i < n; i++){
			dist[i] = new double[n];
			visited[i] = false;
		}
		for(int i = 0; i< n; i++){
			for(int j= 0 ;j < n; j++){
				cin >> dist[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			Path(0, i, n, path, dist, visited);
			visited[i] = false;
		}
		cout.precision(10);
		cout << fixed << result << endl;
		delete [] path;
		delete [] visited;
		for(int i = 0 ; i< n; i++)
			delete [] dist[i];
		delete [] dist;
	}
	return 0;
	
}
	

