#include <iostream>
using namespace std;
#define MAX 101

int main()
{
	int r[MAX];
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		fill(r, r+MAX, 0);
		for (int i=1; i<=n; ++i)
			for (int j=i; j<=n; j+=i)
				r[j] = !r[j];

		int ans = 0;
		for (int i=1; i<=n; ++i)
			if (r[i])
				ans++;

		cout << ans << '\n';
	}

	return 0;
}
