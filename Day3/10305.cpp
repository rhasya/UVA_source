#include <iostream>
using namespace std;

int a[100][100];
int ind[100];
int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;

		// init
		for (int i = 0; i < 100; ++i) {
			ind[i] = 0;
			for (int j = 0; j < 100; ++j) {
				a[i][j] = 0;
			}
		}

		for (int i = 0; i < m; ++i) {
			int s, e;
			cin >> s >> e;

			a[s - 1][e - 1] = 1;
		}

		// calc ind array
		while (true) {
			int target = -1;
			for (int j = 0; j < n; ++j) {
				if (ind[j] == -1) continue;
				int cnt = 0;
				for (int i = 0; i < n; ++i) {
					cnt += a[i][j];
				}
				ind[j] = cnt;
				if (cnt == 0 && target == -1) target = j;
			}

			// find 0
			if (target != -1) {
				cout << target + 1 << " ";
				ind[target] = -1;
			}
			else
				break;
			
			// remove all edge
			for (int j = 0; j < n; ++j) {
				a[target][j] = 0;
			}
		}

		cout << endl;
	}
}