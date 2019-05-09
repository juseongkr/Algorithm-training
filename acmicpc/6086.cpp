#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 52
#define MAX_VAL 1000000
int capa[MAX][MAX], flow[MAX][MAX], pre[MAX];
vector<int> graph[MAX];
int ans, total;

int conv(char c)
{
	if (c <= 'Z')
		return c - 'A';
	return c - 'a' + 26;
}

int main()
{
	int n, c, start, end;
	char a, b;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b >> c;
		a = conv(a);
		b = conv(b);
		capa[a][b] = capa[b][a] += c;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	start = conv('A');
	end = conv('Z');
	while (1) {
		queue<int> que;
		fill(pre, pre+MAX, -1);
		que.push(start);
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			if (cur == end)
				break;
			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i];
				if (capa[cur][next] > flow[cur][next] && pre[next] == -1) {
					que.push(next);
					pre[next] = cur;
				}
			}
		}
		if (pre[end] == -1)
			break;

		int min_flow = MAX_VAL;
		for (int i=end; i!=start; i=pre[i])
			min_flow = min(min_flow, capa[pre[i]][i] - flow[pre[i]][i]);
	
		for (int i=end; i!=start; i=pre[i]) {
			flow[pre[i]][i] += min_flow;
			flow[i][pre[i]] -= min_flow;
		}
		total += min_flow;
	}
	cout << total << '\n';

	return 0;
}
