#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int* network = new int[n];
    for (int i = 0; i < n; i++) {
        network[i] = i;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (computers[i][j] == 1) {
                int tmp = network[j];
                for (int k = 0; k < n; k++) {
                    if (tmp == network[k]) {
                        network[k] = network[i];
                    }
                }
            }
        }
    }
    set<int> tmp;
    for (int i = 0; i < n; i++) {
        tmp.insert(network[i]);
    }
    
    return tmp.size();
}
