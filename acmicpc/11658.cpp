#include <iostream>
using namespace std;
#define MAX 1025

int n, m, t, x, y, x1, x2, y1, y2, c;
int num[MAX][MAX], tree[MAX][MAX];

void update(int x, int y, int val)
{
	for (int i=x; i<=n; i+=i&-i)
		for (int j=y; j<=n; j+=j&-j)
			tree[i][j] += val;
}

int sum(int x, int y)
{
	int ret = 0;
	for (int i=x; i>0; i-=i&-i)
		for (int j=y; j>0; j-=j&-j)
			ret += tree[i][j];
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			cin >> num[i][j];
			update(i, j, num[i][j]);
		}
	}

	while (m--) {
		cin >> t;
		if (t == 0) {
			cin >> x >> y >> c;
			update(x, y, c - num[x][y]);
			num[x][y] = c;
		} else {
			cin >> x1 >> y1 >> x2 >> y2;
			int ret = sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
			cout << ret << '\n';
		}
	}

	return 0;
}
