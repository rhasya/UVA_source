#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
	int x, y, t;
	Edge() : x(0), y(0), t(0) {}
	Edge(int x, int y, int t) : x(x), y(y), t(t) {}
};

Edge g[2000];
int D[2][1000];
int last[1000];

int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int N, M;
		cin >> N >> M;

		for (int i = 0; i < N; ++i) {
			D[0][i] = (int)1e9;
			D[1][i] = (int)1e9;
		}
		D[0][0] = 0;	// start position

		// input edges
		for (int i = 0; i < M; ++i) {
			int x, y, t;
			cin >> x >> y >> t;
			Edge edge(x, y, t);
			g[i] = edge;
		}

		// Do Bellman-ford
		int cur = 0;
		for (int i = 0; i < N; ++i) {
			// copy data
			for (int j = 0; j < N; ++j) D[!cur][j] = D[cur][j];

			for (int j = 0; j < M; ++j) {
				// use all edges
				Edge edge = g[j];
				if (D[cur][edge.x] != 1e9) {
					D[!cur][edge.y] = min(D[!cur][edge.y], D[cur][edge.x] + edge.t);
				}
			}
			cur = !cur;
		}

		// check negative cycle
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			if (D[0][i] != D[1][i]) {
				ans = 1;
				break;
			}
		}

		if (ans) {
			cout << "possible" << endl;
		}
		else {
			cout << "not possible" << endl;
		}
	}
	return 0;
}