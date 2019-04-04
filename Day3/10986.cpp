#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> g[20000];
int visit[20000];
int D[20000];

struct comp {
	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		if (p1.second > p2.second) return true;
		return false;
	}
};

/* 10986 : Sending email */
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, M, S, E;
		cin >> N >> M >> S >> E;
		
		// initialize
		for (int i = 0; i < N; ++i) {
			g[i].resize(0);
			g[i].clear();
			visit[i] = 0;
			D[i] = (int)1e9;
		}

		// make graph
		for (int i = 0; i < M; ++i) {
			int s, e, c;
			cin >> s >> e >> c;
			g[s].push_back(pair<int, int>(e, c));
			g[e].push_back(pair<int, int>(s, c));
		}

		// do dijkstra
		priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
		pq.push(pair<int, int>(S, 0));		// (start, cost 0)
		D[S] = 0;

		while (!pq.empty()) {
			int from = pq.top().first;
			pq.pop();
			
			if (visit[from] == 0) {
				visit[from] = 1;

				// use all edge
				vector<pair<int, int>> edges = g[from];
				for (vector<pair<int, int>>::iterator it = edges.begin(); it != edges.end(); it++) {
					int to = it->first;
					// process only non-visit vertex
					if (visit[to] == 0) {
						D[to] = min(D[to], D[from] + it->second);
						pq.push(pair<int, int>(to, D[to]));
					}
				}
			}
		}

		cout << "Case #" << t << ": ";
		if (visit[E] == 0)
			cout << "unreachable" << endl;
		else
			cout << D[E] << endl;
	}

	return 0;
}