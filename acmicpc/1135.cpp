#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 51
typedef pair<int, int> pii;

int n, k;
vector<pii> graph[MAX];

int dfs(int cur)
{
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].second;
		graph[cur][i].first = dfs(next) + 1;
	}

	sort(graph[cur].rbegin(), graph[cur].rend());

	int depth = 0;
	for (int i=0; i<graph[cur].size(); ++i) {
		graph[cur][i].first += i;
		depth = max(depth, graph[cur][i].first);
	}

	return depth;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		if (k != -1)
			graph[k].push_back({0, i});
	}
	cout << dfs(0) << '\n';

	return 0;
}
