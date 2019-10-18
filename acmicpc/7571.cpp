#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> x, y;
	int n, m, a, b;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int mx = x[m/2];
	int my = y[m/2];

	int ans = 0;
	for (int i=0; i<m; ++i)
		ans += abs(mx - x[i]) + abs(my - y[i]);

	cout << ans << '\n';

	return 0;
}
