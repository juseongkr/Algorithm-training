#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

int n, m, k, x, y;
bool visit[MAX];
vector<int> lower[MAX], upper[MAX];

int bfs(int cur, bool flag)
{
	queue<int> que;
	visit[cur] = 1;
	que.push(cur);

	int cnt = 0;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (flag) {
			for (int i=0; i<lower[cur].size(); ++i) {
				int next = lower[cur][i];
				if (!visit[next]) {
					visit[next] = 1;
					que.push(next);
					cnt++;
				}
			}
		} else {
			for (int i=0; i<upper[cur].size(); ++i) {
				int next = upper[cur][i];
				if (!visit[next]) {
					visit[next] = 1;
					que.push(next);
					cnt++;
				}
			}
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		upper[x].push_back(y);
		lower[y].push_back(x);
	}

	int l = bfs(k, 1);
	int r = bfs(k, 0);

	cout << l+1 << " " << n-r << '\n';

	return 0;
}
