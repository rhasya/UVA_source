#include <iostream>
using namespace std;

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

int a[10001];
int d[10001];
/* 10684 : The jackpot */
int main() {
	int n;
	while (cin >> n) {
		if (n == 0) break;

		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}

		// let's find max value
		// d[i] = max(d[i - 1] + a[i], a[i])
		int ans = 0;
		d[0] = 0;
		for (int i = 1; i <= n; ++i) {
			d[i] = MAX(d[i - 1] + a[i], a[i]);
			ans = MAX(ans, d[i]);
		}

		if (ans > 0)
			cout << "The maximum winning streak is " << ans << ".\n";
		else
			cout << "Losing streak.\n";
	}
	return 0;
}