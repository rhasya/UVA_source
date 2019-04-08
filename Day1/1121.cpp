#include <iostream>
using namespace std;

int A[100000];

/* 1121 - Subsequence */
int main() {
	int N, S;

	while (cin >> N >> S && !cin.eof()) {
		int ans = N + 1;
		int sum = 0;

		int front = 0;
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
			sum += A[i];

			if (sum >= S) {
				while (front < i && sum - A[front] >= S) {
					sum -= A[front];
					front++;
				}
				if (ans > i - front + 1) {
					ans = i - front + 1;
				}
			}
		}

		if (ans == N + 1) {
			ans = 0;
		}
		cout << ans << endl;
	}

	return 0;
}
