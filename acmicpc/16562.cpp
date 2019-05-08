#include <iostream>
using namespace std;

int p[10001], price[10001];

int find(int n)
{
	if (p[n] == n)
		return n;
	p[n] = find(p[n]);
	return p[n];
}

void uni(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if (x != y) {
		if (price[x] < price[y])
			p[y] = x;
		else
			p[x] = y;
	}
}

int main()
{
	int n, m, k, t, a, b, sum = 0;

	scanf("%d %d %d", &n, &m, &k);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &t);
		price[i] = t;
		p[i] = i;
	}

	for (int i=1; i<=m; ++i) {
		scanf("%d %d", &a, &b);
		uni(a, b);
	}

	for (int i=1; i<=n; ++i)
		if (p[i] == i)
			sum += price[i];
	
	if (k >= sum)
		printf("%d\n", sum);
	else
		printf("Oh no\n");

	return 0;
}
