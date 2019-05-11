#include <iostream>
using namespace std;

bool check[1001], prime[1001];

int main()
{
	int n, t, cnt = 0;

	fill(check+2, check+1001, true);
	for (int i=2; i<1001; ++i) {
		if (check[i])
			prime[i] = true;
		for (int j=i; j<1001; j+=i)
			check[j] = false;
	}
	
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		if (prime[t])
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
