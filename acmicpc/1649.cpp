#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define MAX 1001

int n, m, x, y, a, b, k;
int in[MAX], cnt[MAX], dp[MAX];
vector<int> graph[MAX];
set<int> st;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		in[y]++;
	}
	cin >> a >> b >> k;
	for (int i=0; i<k; ++i) {
		cin >> x;
		st.insert(x);
	}

	queue<int> que;
	for (int i=1; i<=n; ++i)
		if (!in[i])
			que.push(i);

	dp[a] = 1;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (st.count(cur))
			cnt[cur]++;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (cnt[cur] == cnt[next]) {
				dp[next] += dp[cur];
			} else if (cnt[cur] > cnt[next]) {
				cnt[next] = cnt[cur];
				dp[next] = dp[cur];
			}

			if (--in[next] == 0)
				que.push(next);
		}
	}
	if (cnt[b] == st.size())
		cout << dp[b] << '\n';
	else
		cout << "0\n";

	return 0;
}
