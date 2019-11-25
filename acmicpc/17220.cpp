#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 27

vector<int> graph[MAX];
bool visit[MAX];
int in[MAX];
int n, m, k, ans;
char s, p;

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> s >> p;
		in[p-'A']++;
		graph[s-'A'].push_back(p-'A');
	}

	cin >> k;
	for (int i=0; i<k; ++i) {
		cin >> s;
		visit[s-'A'] = 1;
	}

	queue<int> que;
	for (int i=0; i<n; ++i) {
		if (in[i] || visit[i])
			continue;
		que.push(i);
		visit[i] = 1;
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (visit[next])
				continue;

			visit[next] = 1;
			que.push(next);
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
