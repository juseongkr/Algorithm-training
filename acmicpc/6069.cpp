#include <iostream>
using namespace std;
#define MAX 501

int a[MAX];

int main()
{
	int n, m, c, x, y;

	cin >> n >> m;
	while (m--) {
		cin >> c >> x >> y;
		if (c) {
			int ans = 0;
			for (int i=x; i<=y; ++i)
				if (a[i] % 2 != 0)
					ans++;
			cout << ans << '\n';
		} else {
			for (int i=x; i<=y; ++i)
				a[i]++;
		}
	}

	return 0;
}
