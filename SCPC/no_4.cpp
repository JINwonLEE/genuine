#include <iostream>

using namespace std;

int Answer;
bool line[100][100];
int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int N, M; // 5 <= N <= 100 and 4 <= M <= 1000
        cin >> N >> M;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                line[i][j] = false;
            }
        }

        for (int i = 0; i < M; i++) {
            int start, end;
            cin >> start >> end;
            line[start][end] = true;
            line[end][start] = true;
        }

		Answer = 0;
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
