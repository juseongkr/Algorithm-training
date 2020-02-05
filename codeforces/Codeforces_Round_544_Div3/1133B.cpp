#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> m;
int n, k, p;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> p;
		m[p%k]++;
	}

	int ans = 0;
	for (int i=0; i<=k/2; ++i) {
		int j = (k-i) % k;
		if (i == j)
			ans += m[i]/2;
		else
			ans += min(m[i], m[j]);
	}
	cout << ans * 2 << '\n';

	return 0;
}
