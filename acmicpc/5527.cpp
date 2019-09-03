#include <iostream>
using namespace std;
#define MAX 100001

int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, t;

	cin >> n;
	int prev = -1, idx = 1;
	for (int i=0; i<n; ++i) {
		cin >> t;
		if (prev == t)
			idx++;
		prev = t;
		num[idx]++;
	}

	int ans = 0;
	for (int i=1; i<=idx; ++i)
		ans = max(ans, num[i-1] + num[i] + num[i+1]);

	cout << ans << '\n';

	return 0;
}
