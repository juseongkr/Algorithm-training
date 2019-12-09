#include <iostream>
using namespace std;
#define MAX 200001

int num[MAX], p[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		fill(p, p+MAX, -1);
		for (int i=0; i<n; ++i)
			cin >> num[i];

		int ans = n+1;
		for (int i=0; i<n; ++i) {
			if (p[num[i]] >= 0)
				ans = min(ans, i-p[num[i]]+1);
			p[num[i]] = i;
		}

		if (ans == n+1)
			cout << "-1\n";
		else
			cout << ans << '\n';
	}

	return 0;
}
