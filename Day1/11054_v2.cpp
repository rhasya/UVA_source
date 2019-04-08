#include <iostream>
#include <cstdlib>
using namespace std;

int A[100000];

/* 11054 - Wine trading in Gergovia */
int main() {
	int N;
	while (true) {
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; ++i)
			cin >> A[i];

		long long ans = 0;
		long long remain = 0;
		for (int i = 0; i < N; ++i) {
			remain += A[i];
			ans += abs(remain);
		}
		cout << ans << endl;
	}

	return 0;
}
