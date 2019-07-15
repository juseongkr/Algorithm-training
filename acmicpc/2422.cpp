#include <iostream>
using namespace std;
#define MAX 201

int main()
{
	int n, m, a, b;
	int no[MAX][MAX];

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		no[a][b] = no[b][a] = 1;
	}

	int ans = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=i+1; j<=n; ++j) {
			for (int k=j+1; k<=n; ++k) {
				if (no[i][j] || no[j][k] || no[i][k])
					continue;
				ans++;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
