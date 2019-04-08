#include <iostream>
#include <cstdlib>
using namespace std;

int A[100000];

/* 11054 Wine trading in Gergovia */
int main() {
	int N;
	while (true) {
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; ++i)
			cin >> A[i];
		
		int p_idx = 0;
		int m_idx = 0;
		while (A[p_idx] < 0) p_idx++;
		while (A[m_idx] >= 0) m_idx++;

		long long ans = 0;
		while (p_idx < N && m_idx < N) {
			if (A[p_idx] > -A[m_idx]) {
				int v = -A[m_idx];
				A[p_idx] += A[m_idx];
				A[m_idx] = 0;
				ans += abs(m_idx - p_idx) * v;
				while (A[m_idx] >= 0 && m_idx < N) m_idx++;
			}
			else {
				int v = A[p_idx];
				A[m_idx] += A[p_idx];
				A[p_idx] = 0;
				ans += abs(m_idx - p_idx) * v;
				while (A[p_idx] <= 0 && p_idx < N) p_idx++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
