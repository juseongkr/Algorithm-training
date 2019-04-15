#include <iostream>
using namespace std;

int main()
{
	long long memo[1000001];
	long long num;

	scanf("%lld", &num);
	memo[1] = 0;
	for (int i=2; i<=num; ++i) {
		memo[i] = memo[i-1] + 1;
		if (i % 3 == 0)
			memo[i] = min(memo[i], memo[i/3]+1);
		else if (i % 2 == 0)
			memo[i] = min(memo[i], memo[i/2]+1);
	}

	printf("%lld\n", memo[num]);

	return 0;
}
