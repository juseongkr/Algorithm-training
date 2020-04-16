#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 200001

int T, n, k, x, y;
vector<int> graph[MAX], vec;

int dfs(int cur, int prev, int dep)
{
	int child = 0;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next != prev)
			child += dfs(next, cur, dep+1);
	}
	vec.push_back(dep - child);
	return child+1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1, 0, 0);
	sort(vec.rbegin(), vec.rend());

	long long ans = 0;
	for (int i=0; i<vec.size(); ++i) {
		ans += vec[i];
		if (--k == 0)
			break;
	}
	cout << ans << '\n';

	return 0;
}
