#include <iostream>
using namespace std;
#define MAX 101

int w, h, n, x, y;
int p[MAX];

int main()
{
	cin >> w >> h >> n;
	for (int i=0; i<=n; ++i) {
		cin >> x >> y;
		if (x == 1)
			p[i] = y;
		else if (x == 2)
			p[i] = 2 * w + h - y;
		else if (x == 3)
			p[i] = 2 * w + 2 * h - y;
		else
			p[i] = w + y;
	}

	int ans = 0;
	for (int i=0; i<n; ++i) {
		int dist = abs(p[n] - p[i]);
		if (dist < w+h)
			ans += dist;
		else
			ans += 2*(w+h) - dist;
	}
	cout << ans << '\n';

	return 0;
}
