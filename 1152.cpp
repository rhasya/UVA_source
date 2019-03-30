#include <iostream>
#include <algorithm>
using namespace std;

long long A[4000][4];
long long CD[4000 * 4000];
/* 1152 - 4 Values whose Sum is 0 */
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; ++t) {
		if (t != 0) printf("\n");

		int N;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%lld", &A[i][j]);
			}
		}

		// make C+D
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				CD[i * N + j] = A[i][2] + A[j][3];
			}
		}

		// sort CD
		sort(CD, CD + N * N);

		long long answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				long long s = 0;
				s += A[i][0];
				s += A[j][1];

				long long *lower = lower_bound(CD, CD + N * N, -s);
				long long *upper = upper_bound(CD, CD + N * N, -s);
				if (lower < CD + N * N && *lower == -s) {
					answer += (upper - lower);
				}
			}
		}

		printf("%lld\n", answer);
	}

	return 0;
}
