#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string P, Q;
		cin >> P >> Q;
		P.erase(remove(P.begin(), P.end(), ' '), P.end());
		Q.erase(remove(Q.begin(), Q.end(), ' '), Q.end());

		string answer = "";
		int index = 0;
		int upper = 0;
		while (index < P.size() && index < Q.size()) {
			if (Q[index] - P[index] >= 1) {
				answer = "Y";
				break;
			}
			index++;
		}

		if (answer == "") {
			if (Q.size() == P.size() || (Q[P.size()] == 'a' && Q.size() == P.size() + 1)) answer = "N";
			else answer = "Y";
		}
		cout << "#" << i + 1 << " " << answer << endl;
	}
}

