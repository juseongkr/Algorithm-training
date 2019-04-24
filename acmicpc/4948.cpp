#include <iostream>
using namespace std;

#define MAX_VAL 123456*2+1

int main()
{
	bool prime[MAX_VAL];
	int n, cnt;

	while (1) {
		cnt = 0;
		fill(prime+2, prime+MAX_VAL, true);
		scanf("%d", &n);
		if (n == 0)
			break;

		for (int i=2; i<=2*n; ++i) {
			if (prime[i])
				cnt++;
			for (int j=i; j<=2*n; j+=i)
				prime[j] = false;
		}

		fill(prime+2, prime+MAX_VAL, true);

		for (int i=2; i<=n; ++i) {
			if (prime[i])
				cnt--;
			for (int j=i; j<=2*n; j+=i)
				prime[j] = false;
		}

		printf("%d\n", cnt);
	}

	return 0;
}
