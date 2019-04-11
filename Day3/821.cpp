#include <iostream>
#include <algorithm>
using namespace std;

int D[101][101];
/* 821 - Page hopping */
int main() {
	int x, y, t = 0;
	while (cin >> x >> y && x != 0 && y != 0) {
		t++;

		// x, y is first edge

		// initialize
		for (int i = 1; i <= 100; ++i) {
			for (int j = 1; j <= 100; ++j) {
				if (i == j) D[i][j] = 0;
				else D[i][j] = (int) 1e9;
			}
		}

		// input and save
		do {
			D[x][y] = 1;
		} while (cin >> x >> y && x != 0 && y != 0);

		// floyd-warsharl
		for (int k = 1; k <= 100; ++k) {
			for (int i = 1; i <= 100; ++i) {
				for (int j = 1; j <= 100; ++j) {
					if (k != i && k != j) {
						D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
					}
				}
			}
		}

		// calculate average
		double sum = 0;
		int cnt = 0;
		for (int i = 1; i <= 100; ++i) {
			for (int j = 1; j <= 100; ++j) {
				if (i != j && D[i][j] < (int)1e9) {
					sum += D[i][j];
					cnt++;
				}
			}
		}

		cout << "Case " << t << ": average length between pages = ";
		printf("%.3f clicks\n", sum / cnt);
	}
	return 0;
}