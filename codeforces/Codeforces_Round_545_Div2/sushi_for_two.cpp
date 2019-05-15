#include <iostream>
using namespace std;
int len[100005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int num[100005];
	int n, idx = 0, ans = 0;

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> num[i];

	for (int i=1; i<=n; ++i) {
		if (num[i] != num[i-1])
			idx++;
		len[idx]++;
	}

	for (int i=1; i<idx; ++i)
		ans = max(ans, 2 * min(len[i], len[i+1]));

	cout << ans << '\n';

	return 0;
}
