#include <iostream>
using namespace std;

int num[1001], sub[1001];

int main()
{
	int n, m, a, b;

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		cin >> num[i];
	
	for (int i=1; i<n; ++i)
		sub[i] = abs(num[i]-num[i+1]);

	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		int ans = 0;
		for (int i=a; i<b; ++i)
			ans += sub[i];
		
		cout << ans << '\n';
	}

	return 0;
}
