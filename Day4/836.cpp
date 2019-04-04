#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

int A[25 + 1][25 + 1];
int D[25 + 1][25 + 1];
int V[25 + 1][25 + 1];
int main() {
	int T;
	cin >> T;
	getchar(); getchar();
	for (int t = 1; t <= T; ++t) {
		if (t != 1)
			cout << endl;

		int i = 1, j = 1;
		int N = 0;
		char ch = getchar();

		while (ch != '\n' && ch > 0) {
			while (ch != '\n') {
				A[i][j++] = ch - '0';
				ch = getchar();
			}
			i++;
			N = j - 1;
			j = 1;
			ch = getchar();
		}

		// init
		for (int i = 0; i <= N; ++i) {
			for (int j = 0; j <= N; ++j) {
				D[i][j] = 0;
			}
		}

		// D[i][j] = D[i][j]ÀÇ width
		// D[i][j] = D[i][j - 1] + 1
		// V[i][j] = A[i][j] is right-bottom' rectungure sizes
		D[0][0] = 0;
		int mx = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (A[i][j] == 1) {
					D[i][j] = D[i][j - 1] + 1;
					
					int h = 1, w = D[i][j];
					V[i][j] = 0;
					while (A[i - h + 1][j] == 1) {
						w = min(w, D[i - h + 1][j]);
						V[i][j] = max(V[i][j], w * h);
						h++;
					}
				}
				else {
					D[i][j] = 0;
					V[i][j] = 0;
				}
				if (mx < V[i][j])
					mx = V[i][j];
			}
		}

		cout << mx << endl;
	}
	return 0;
}