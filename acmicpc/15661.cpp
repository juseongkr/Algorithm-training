#include <iostream>
using namespace std;
#define MAX 21

int n, ans = 10000;
int map[MAX][MAX], visit[MAX];

void dfs(int cnt, int d)
{
	if (d == n / 2) {
		int s = 0, l = 0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (visit[i] && visit[j])
					s += map[i][j];
				if (!visit[i] && !visit[j])
					l += map[i][j];
			}
		}
		ans = min(ans, abs(s - l));
	}

	for (int i=cnt; i<n; ++i) {
		visit[i] = 1;
		dfs(i+1, d+1);
		visit[i] = 0;
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	dfs(0, 0);

	cout << ans << '\n';

	return 0;
}
