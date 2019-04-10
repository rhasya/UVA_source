#include <iostream>
#include <queue>
using namespace std;

struct Line {
	int s, e, c;
	Line() : s(0), e(0), c(0) {}
	Line(int s, int e, int c) : s(s), e(e), c(c) {}

	bool operator()(const Line& lhs, const Line& rhs) {
		if (lhs.c == rhs.c && lhs.s == rhs.s) return lhs.e > rhs.e;
		if (lhs.c == rhs.c) return lhs.s > rhs.s;
		return lhs.c > rhs.c;
	}
};

int p[1000001];

int find(int a) {
	if (a == p[a]) return a;
	else return p[a] = find(p[a]);
}

int main() {
	int N, T = 0;
	while (cin >> N && !cin.eof()) {
		if (T++ != 0) cout << endl;

		// initialize
		for (int i = 1; i <= N; ++i) {
			p[i] = i;
		}

		// input N - 1 original optimized lines
		int orig = 0;
		for (int i = 0; i < N - 1; ++i) {
			int s, e, c;
			cin >> s >> e >> c;
			orig += c;
		}

		// make priority queue
		priority_queue<Line, vector<Line>, Line> pq;

		// insert new lines k
		int K;
		cin >> K;
		for (int i = 0; i < K; ++i) {
			int s, e, c;
			cin >> s >> e >> c;
			Line l(s, e, c);
			pq.push(l);
		}

		// insert originl lines m
		int M;
		cin >> M;
		for (int i = 0; i < M; ++i) {
			int s, e, c;
			cin >> s >> e >> c;
			Line l(s, e, c);
			pq.push(l);
		}

		// do kruskal algorithm
		int cost = 0;
		while (!pq.empty()) {
			Line l = pq.top();
			pq.pop();

			// check s, e is same group
			int ps = find(l.s);
			int pe = find(l.e);
			if (ps != pe) {
				// union
				p[pe] = ps;
				cost += l.c;
			}
		}

		cout << orig << endl;
		cout << cost << endl;
	}
	return 0;
}