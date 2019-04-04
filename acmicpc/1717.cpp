#include <iostream>
using namespace std;

int p[1000001];

int find(int n)
{
	if (p[n] == n)
		return n;
	else
		return p[n] = find(p[n]);
}

void uni(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if (x != y)
		p[y] = x;
}

int main()
{
	int n, m, c, a, b;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		p[i] = i;

	for (int i=0; i<m; ++i) {
		scanf("%d %d %d", &c, &a, &b);
		if (c) {
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		} else {
			uni(a, b);
		}
	}

	return 0;
}
