#include <iostream>
using namespace std;

int p[201];

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
	int n, m, v, f;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		p[i] = i;

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			scanf("%d", &v);
			if (v != 0)
				uni(i, j);
		}
	}

	scanf("%d", &f);
	f = find(f);
	for (int i=1; i<m; ++i) {
		scanf("%d", &v);
		if (f != find(v)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	return 0;
}
