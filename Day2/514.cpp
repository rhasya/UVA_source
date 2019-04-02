#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, N;
	bool nl = false;
	while (cin >> T && T != 0) {
		while (true) {
			cin >> N;
			if (N == 0) break;
			// there is T numbers
			vector<int> in(T);
			in[0] = N;
			for (int i = 1; i < T; ++i) {
				cin >> in[i];
			}

			vector<int> st;
			int qu = 1, idx = 0;
			while (qu <= T) {
				if (!st.empty() && st.back() == in[idx]) {
					st.pop_back();
					idx++;
				}
				else if (qu == in[idx]) {
					qu++;
					idx++;
				}
				else {
					st.push_back(qu);
					qu++;
				}
			}

			while (!st.empty() && in[idx] == st.back()) {
				idx++;
				st.pop_back();
			}

			if (st.empty()) cout << "Yes";
			else cout << "No";
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}