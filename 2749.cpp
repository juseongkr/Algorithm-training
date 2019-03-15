#include <stdio.h>

int main()
{
	const long long N = 1000000/10*15;
	long long num;
	int memo[N] = {0, 1};
	scanf("%lld", &num);

	for (int i=2; i<N; ++i) {
		memo[i] = memo[i-1] + memo[i-2];
		memo[i] %= 1000000;
	}

	printf("%d\n", memo[num % N]);

	return 0;
}
