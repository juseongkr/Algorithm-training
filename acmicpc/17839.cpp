#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define MAX 200002

int n, num;
vector<int> graph[MAX];
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	map<string, int> m;
	vector<string> vec;
	string a, b, t;

	vec.push_back("Baba");
	m["Baba"] = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> t >> b;
		if (!m.count(a)) {
			m[a] = ++num;
			vec.push_back(a);
		}
		if (!m.count(b)) {
			m[b] = ++num;
			vec.push_back(b);
		}
		graph[m[a]].push_back(m[b]);
	}

	queue<int> que;
	visit[0] = 1;
	que.push(0);

	vector<string> ans;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (visit[next])
				continue;

			visit[next] = 1;
			que.push(next);
			ans.push_back(vec[next]);
		}
	}
	sort(ans.begin(), ans.end());

	for (int i=0; i<ans.size(); ++i)
		cout << ans[i] << '\n';

	return 0;
}
