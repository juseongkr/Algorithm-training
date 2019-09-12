#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define MAX 1001

set<int> x_set, y_set;
map<int, int> x_hash, y_hash;
int pos[MAX][MAX], p[MAX][MAX];
int x[MAX], y[MAX];

int sum(int x1, int y1, int x2, int y2)
{
	return p[x2][y2] - p[x2][y1] - p[x1][y2] + p[x1][y1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
		x_set.insert(x[i]);
		y_set.insert(y[i]);
	}

	int X = 0, Y = 0;
	for (auto i : x_set)
		x_hash[i] = X++;

	for (auto i : y_set)
		y_hash[i] = Y++;

	for (int i=0; i<n; ++i)
		pos[x_hash[x[i]]][y_hash[y[i]]]++;

	for (int i=0; i<X; ++i)
		for (int j=0; j<Y; ++j)
			p[i+1][j+1] = p[i+1][j] + p[i][j+1] - p[i][j] + pos[i][j];

	int ans = n;
	for (int i=0; i<=X; ++i) {
		for (int j=0; j<=Y; ++j) {
			int ret = max({sum(0, 0, i, j),
					sum(i, j, X, Y),
					sum(0, j, i, Y),
					sum(i, 0, X, j)});
			ans = min(ans, ret);
		}
	}
	cout << ans << '\n';

	return 0;
}
