#include <iostream>
using namespace std;

int p[30001];
int cnt[30001];

/* 10608 Friends */

int find(int a) {
	if (a == p[a]) return a;
	else return p[a] = find(p[a]);
}

int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int N, M;
		cin >> N >> M;

		for (int i = 1; i <= N; ++i) {
			p[i] = i;
			cnt[i] = 0;
		}
		
		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;

			// union
			int pa = find(a);
			int pb = find(b);
			if (pa != pb)
				p[pa] = pb;
		}

		// find maximum group size
		int mx = 0;
		for (int i = 1; i <= N; ++i) {
			int x = find(i);
			cnt[x]++;
			if (mx < cnt[x]) mx = cnt[x];
		}
		cout << mx << endl;
	}
	return 0;
}