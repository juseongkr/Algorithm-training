#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 301
const int INF = 1e5+1;

int n, m, k, a, b, c;
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> n >> m >> k;
		if (n == 0)
			break;

		vector<pair<int, int>> dragon[MAX];
		vector<int> graph[MAX];

		for (int i=0; i<m; ++i) {
			cin >> a >> b;
			a--;
			b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i=0; i<k; ++i) {
			cin >> a >> b >> c;
			a--;
			dragon[a].push_back({b, c});
		}

		int ans = 0;
		fill(visit, visit+MAX, 0);
		for (int i=0; i<n; ++i) {
			if (visit[i])
				continue;

			queue<int> que;
			vector<int> vec;
			visit[i] = true;
			que.push(i);

			int cnt = 0;
			while (!que.empty()) {
				int cur = que.front();
				vec.push_back(cur);
				cnt += dragon[cur].size();
				que.pop();

				for (int i=0; i<graph[cur].size(); ++i) {
					int next = graph[cur][i];
					if (!visit[next]) {
						visit[next] = true;
						que.push(next);
					}
				}
			}
			if (!cnt)
				continue;

			int l = 0, r = INF, val;
			while (l <= r) {
				int sum = 0;
				int mid = (l+r)/2;
				for (int i : vec)
					for (auto &p : dragon[i])
						if (p.second >= mid)
							sum += p.first;

				if (sum <= mid) {
					r = mid-1;
					val = mid;
				} else {
					l = mid+1;
				}
			}
			ans += val;
		}
		cout << ans << '\n';
	}
	return 0;
}
