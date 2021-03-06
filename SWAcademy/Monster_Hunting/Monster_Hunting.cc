#include <iostream>

using namespace std;

int main() {
	int T, D, L, N;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> D >> L >> N;
		int answer = 0;
		for (int j = 0; j < N; j++) {
			double per = j * 0.01 * L;
			answer += (double)D * (1 + per);
		}

		cout << "#" << i + 1 << " " << answer << endl;
	}


	return 0;
}
