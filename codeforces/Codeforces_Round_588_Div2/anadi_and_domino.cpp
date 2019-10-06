#include <iostream>
#include <cstring>
using namespace std;
#define MAX 51

int n, m, u, v, ans;
pair<int, int> graph[MAX];
int num[7][7], digit[7];

void dfs(int x)
{
	if (x == n+1) {
		memset(num, 0, sizeof(num));
		for (int i=1; i<=m; ++i) {
			int a = digit[graph[i].first];
			int b = digit[graph[i].second];
			num[a][b]++;
		}
		int cnt = 0;
		for (int i=1; i<=6; ++i)
			for (int j=i; j<=6; ++j)
				if (num[i][j])
					cnt++;
		ans = max(ans, cnt);
		return;
	}

	for (int i=1; i<=6; ++i) {
		digit[x] = i;
		dfs(x+1);
	}
}

int main()
{
	cin >> n >> m;
	for (int i=1; i<=m; ++i) {
		cin >> u >> v;
		if (u > v)
			swap(u, v);
		graph[i] = {u, v};
	}
	dfs(1);
	cout << ans << '\n';

	return 0;
}
