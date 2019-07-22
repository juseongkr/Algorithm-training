#include <iostream>
using namespace std;
#define MAX 4

int main()
{
	int k, n, w;
	int dir[MAX];
	string a[MAX];

	for (int i=0; i<MAX; ++i)
		cin >> a[i];

	cin >> k;
	while (k--) {
		fill(dir, dir+MAX, 0);
		cin >> n >> w;
		dir[--n] = w;

		for (int i=n-1; i>=0; i--) {
			if (a[i][2] != a[i+1][6])
				dir[i] = dir[i+1] * -1;
			else
				break;
		}

		for (int i=n+1; i<MAX; ++i) {
			if (a[i-1][2] != a[i][6])
				dir[i] = dir[i-1] * -1;
			else
				break;
		}

		for (int i=0; i<MAX; ++i) {
			if (dir[i] == 1) {
				char t = a[i][7];
				for (int j=7; j>=0; j--)
					a[i][j] = a[i][j-1];
				a[i][0] = t;
			} else if (dir[i] == -1) {
				char t = a[i][0];
				for (int j=0; j<7; ++j)
					a[i][j] = a[i][j+1];
				a[i][7] = t;
			} else {
				continue;
			}
		}
	}

	int ans = 0;
	for (int i=0; i<MAX; ++i)
		if (a[i][0] == '1')
			ans |= (1 << i);

	cout << ans << '\n';

	return 0;
}
