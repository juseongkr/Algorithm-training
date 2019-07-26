#include <iostream>
using namespace std;
#define MAX 1000001

int p[MAX];

int find(int n)
{
	if (p[n] < 0)
		return n;
	return p[n] = find(p[n]);
}

void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y) {
		p[x] += p[y];
		p[y] = x;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, a, b, c;

	cin >> n >> m;
	fill(p, p+MAX, -1);
	for (int i=0; i<m; ++i) {
		cin >> c >> a >> b;
		if (c) {
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		} else {
			uni(a, b);
		}
	}

	return 0;
}
