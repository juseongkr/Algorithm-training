#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num[MAX][MAX], query[MAX];
	int n, m, q;

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> num[i][j];

	cin >> q;
	while (q--) {
		for (int i=0; i<m; ++i)
			cin >> query[i];
		int ans = 0;
		for (int i=0; i<n; ++i) {
			bool flag = true;
			for (int j=0; j<m; ++j) {
				if (query[j] == -1)
					continue;
				if (query[j] != num[i][j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}
