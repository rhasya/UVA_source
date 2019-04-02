#include <iostream>
using namespace std;

#define SGN(x) ((x) > 0 ? 1 : (x) < 0 ? -1 : 0)

int T[1 << 18];		// 1 << 18 near 200000
int main() {
	int N, K;
	while (cin >> N >> K) {
		// find base
		int t = N - 1;
		int base = 0;
		while (t > 0) {
			t >>= 1;
			base++;
		}
		base = 1 << base;

		// make default tree
		for (int i = 0; i < N; ++i)
			cin >> T[base + i];

		for (int i = base - 1; i >= 1; --i) {
			T[i] = SGN(T[i * 2]) * SGN(T[i * 2 + 1]);
		}
		
		// solve query
		for (int i = 0; i < K; ++i) {
			char c;
			int s, e;
			cin >> c >> s >> e;

			if (c == 'C') {
				// update
				s += base - 1;
				T[s] = e;
				while (s > 1) {
					s >>= 1;
					T[s] = SGN(T[s * 2]) * SGN(T[s * 2 + 1]);
				}
			}
			else {
				// get
				s += base - 1; e += base - 1;
				int r = 1;
				while (s <= e) {
					// get left
					if (s % 2 == 0) s /= 2;
					else {
						r *= SGN(T[s]);
						s = (s + 1) / 2;
					}
					// get right
					if (e % 2 == 1) e /= 2;
					else {
						r *= SGN(T[e]);
						e = (e - 1) / 2;
					}
				}
				if (r > 0) cout << '+';
				else if (r < 0) cout << '-';
				else cout << '0';
			}
		}
		cout << endl;
	}

	return 0;
}