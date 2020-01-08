#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001

int n, sx, sy, x, y, u, d, l, r;

int main()
{
	cin >> n >> sx >> sy;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		if (x > sx)
			r++;
		if (x < sx)
			l++;
		if (y > sy)
			u++;
		if (y < sy)
			d++;
	}

	int ans = max({l, r, u, d});
	if (ans == l)
		sx--;
	else if (ans == r)
		sx++;
	else if (ans == u)
		sy++;
	else
		sy--;

	cout << ans << '\n' << sx << ' ' << sy << '\n';

	return 0;
}
