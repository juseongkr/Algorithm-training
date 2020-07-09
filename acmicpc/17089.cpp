#include <iostream>
#include <climits>
using namespace std;
#define MAX 4001

int f[MAX][MAX], in[MAX];

int main()
{
	int n, m, a, b;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		f[a][b] = f[b][a] = 1;
		in[a]++;
		in[b]++;
	}

	int ans = INT_MAX;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (!f[i][j])
				continue;
			for (int k=1; k<=n; ++k) {
				if (f[i][k] && f[j][k]) {
					int ret = in[i] + in[j] + in[k] - 6;
					ans = min(ans, ret);
				}
			}
		}
	}
	if (ans == INT_MAX)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
