#include <iostream>
#include <vector>
using namespace std;
#define MAX 10001

vector<pair<int, int>> graph[MAX];
int visit[MAX], step[MAX];
int n, m, a, b, c, s, e, cnt;

void max_cost(int cur)
{
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int cost = graph[cur][i].second;
		if (!step[next])
			max_cost(next);
		step[cur] = max(step[cur], step[next] + cost);
	}
}

void max_cnt(int n)
{
	if (visit[n])
		return;

	visit[n] = 1;
	for (int i=0; i<graph[n].size(); ++i) {
		int next = graph[n][i].first;
		int cost = graph[n][i].second;
		if (step[n] == step[next] + cost) {
			max_cnt(next);
			cnt++;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		graph[a-1].push_back({b-1, c});
	}
	cin >> s >> e;

	max_cost(s-1);
	max_cnt(s-1);

	cout << step[s-1] << '\n' << cnt << '\n';

	return 0;
}
