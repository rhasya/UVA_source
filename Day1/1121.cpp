#include <iostream>
using namespace std;

int A[100000];
/* 1121 - Subsequence */
int main()
{
	int N, S;
	while (scanf("%d%d", &N, &S) > 0) {
		int ans = N + 1, sum = 0;
		int s = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &A[i]);
			sum += A[i];
			if (sum >= S)
			{
				while (s < i && sum - A[s] >= S) sum -= A[s++];
				if (ans > i - s + 1) ans = i - s + 1;
			}
		}
		if (ans == N + 1) ans = 0;
		printf("%d\n", ans);
	}
	return 0;
}
