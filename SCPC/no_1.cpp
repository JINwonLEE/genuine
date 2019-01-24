#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main(int argc, char** argv)
{
	int T, test_case, Answer;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        int N, K;
        cin >> N >> K;
        vector<int> player;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            player.push_back(tmp);
        }
        
        sort(player.begin(), player.end());
        priority_queue<int,vector<int>, greater<int> > bus_max_num;

        for (int i = 0; i < player.size(); i++) {
            bool embed = false;
            if (!bus_max_num.empty()) {
                int low = bus_max_num.top();
                if (player[i] - low > K) {
                    embed = true;
                    bus_max_num.pop();
                    bus_max_num.push(player[i]);
                }
            }
            if (!embed) {
                bus_max_num.push(player[i]); 
            }
        }

        Answer = bus_max_num.size();
	    cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
