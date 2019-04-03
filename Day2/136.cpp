#include <iostream>
#include <queue>
using namespace std;

typedef long long LL;

int main() {
	int factors[3] = { 2, 3, 5 };

	priority_queue<LL, vector<LL>, greater<LL>> pq;
	pq.emplace(1);

	int cnt = 0;
	LL answer;
	while (cnt < 1500) {
		answer = pq.top();
		for (int i = 0; i < 3; ++i) {
			pq.emplace(answer * factors[i]);
		}
		while(answer == pq.top()) pq.pop();
		cnt++;
	}

	cout << "The 1500'th ugly number is " << answer << "." << endl;

	return 0;
}