#include <iostream>
using namespace std;
#define MAX 11

int s[MAX][MAX], ans;
bool visit[MAX];

void dfs(int cnt, int sum)
{
	if (cnt == 11) {
		ans = max(ans, sum);
		return;
	}

	for (int i=0; i<11; ++i) {
		if (visit[i] || s[cnt][i] == 0)
			continue;
		visit[i] = 1;
		dfs(cnt+1, sum + s[cnt][i]);
		visit[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t;

	cin >> t;
	while (t--) {
		for (int i=0; i<11; ++i)
			for (int j=0; j<11; ++j)
				cin >> s[i][j];

		dfs(0, 0);
		cout << ans << '\n';
		fill(visit, visit+MAX, 0);
		ans = 0;
	}

	return 0;
}
