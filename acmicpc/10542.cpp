#include <iostream>
#include <vector>
using namespace std;
#define MAX 500001

int n, ans;
int in[MAX], to[MAX];
bool visit[MAX];

void dfs(int cur, bool flag=true)
{
	if (visit[cur])
		return;
	visit[cur] = 1;

	ans += flag;
	int next = to[cur];
	if (--in[next] == 0 || flag)
		dfs(next, !flag);
}

int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> to[i];
		in[to[i]]++;
	}

	for (int i=1; i<=n; ++i)
		if (in[i] == 0)
			dfs(i);

	for (int i=1; i<=n; ++i)
		dfs(i, false);

	cout << ans << '\n';

	return 0;
}
