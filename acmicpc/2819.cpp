#include <iostream>
using namespace std;
#define MAX 100000

string s;
int X[MAX*2+1], Y[MAX*2+1];
int n, m, x, y, ax, ay, bx, by, cx, cy;
long long ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		X[x+MAX]++;
		Y[y+MAX]++;
		if (x > 0)
			ax++;
		else if (x < 0)
			cx++;
		else
			bx++;
		if (y > 0)
			ay++;
		else if (y < 0)
			cy++;
		else
			by++;
		
		ans += abs(x) + abs(y);
	}

	cin >> s;
	int sx = MAX, sy = MAX;
	for (int i=0; i<m; ++i) {
		if (s[i] == 'S') {
			sy++;
			ans += (by + cy - ay);
			cy += by;
			by = Y[sy];
			ay -= Y[sy];
		} else if (s[i] == 'Z') {
			sx--;
			ans += (ax + bx - cx);
			ax += bx;
			bx = X[sx];
			cx -= X[sx];
		} else if (s[i] == 'J') {
			sy--;
			ans += (by + ay - cy);
			ay += by;
			by = Y[sy];
			cy -= Y[sy];
		} else {
			sx++;
			ans += (bx + cx - ax);
			cx += bx;
			bx = X[sx];
			ax -= X[sx];
		}
		cout << ans << '\n';
	}

	return 0;
}
