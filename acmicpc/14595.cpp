#include <iostream>
using namespace std;
#define MAX 1000001

int p[MAX];
int n, m, x, y;

int find(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	p[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<=n; ++i)
		p[i] = i;

	int cnt = 0;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		while (find(x) != find(y)) {
			cnt++;
			int z = find(x)+1;
			uni(x, y);
			x = z;
		}
	}

	cout << n - cnt << '\n';

	return 0;
}
