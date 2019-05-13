#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int b[100001], g[100001];
	int n, m;

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> b[i];

	for (int i=0; i<m; ++i)
		cin >> g[i];

	sort(b, b+n);
	sort(g, g+m);

	if (b[n-1] > g[0]) {
		cout << -1 << '\n';
	} else {
		long long sum = 0;
		for (int i=0; i<n-1; ++i)
			sum += b[i] * (long long)m;

		for (int i=0; i<m; ++i)
			sum += g[i];

		if (g[0] != b[n-1])
			sum += (b[n-1] - b[n-2]);
		
		cout << sum << '\n';
	}
	

	return 0;
}
