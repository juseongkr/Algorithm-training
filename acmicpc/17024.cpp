#include <iostream>
using namespace std;
#define MAX 100001

int g[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, x, y;

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		g[x]++;
		g[y]++;
	}

	int ans = 0;
	for (int i=0; i<n; ++i)
		ans = max(ans, g[i]);

	cout << ans+1 << '\n';

	return 0;
}
