#include <iostream>
using namespace std;
#define MAX 100001

int n, m, q, x, y;
int p[MAX], rm[MAX], a[MAX], b[MAX], cut[MAX];

int find(int n)
{
	if (p[n] < 0)
		return n;
	return p[n] = find(p[n]);
}

long long uni(int x, int y)
{
	x = find(x);
	y = find(y);
	long long ret = 0;
	if (x == y) {
		return 0;
	} else {
		ret = p[x] * p[y];
		p[x] += p[y];
		p[y] = x;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> q;
	for (int i=0; i<m; ++i) {
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
	}

	for (int i=0; i<q; ++i) {
		cin >> cut[i];
		cut[i]--;
		rm[cut[i]] = 1;
	}

	long long ans = 0;
	fill(p, p+MAX, -1);
	for (int i=0; i<m; ++i)
		if (rm[i] == 0)
			uni(a[i], b[i]);

	for (int i=q-1; i>=0; i--)
		ans += uni(a[cut[i]], b[cut[i]]);

	cout << ans << '\n';

	return 0;
}
