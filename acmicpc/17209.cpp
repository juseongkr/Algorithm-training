#include <iostream>
#include <vector>
using namespace std;
#define MAX 2001

string s;
int n, x, y;
bool visit[MAX];
vector<int> graph[MAX];

void dfs(int cur, bool flag)
{
	visit[cur] = 1;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (visit[next])
			continue;

		if (flag)
			y++;
		else
			x++;
		dfs(next, !flag);
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<n; ++j) {
			if (s[j] == '1') {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	int ans = 0;
	for (int i=0; i<n; ++i) {
		if (!visit[i]) {
			x = 1;
			y = 0;
			dfs(i, 1);
			ans += max(x, y);
		}
	}

	cout << ans << '\n';

	return 0;
}
