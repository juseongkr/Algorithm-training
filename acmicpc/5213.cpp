#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 501

int n, cur;
int map[MAX][MAX*2], tile[MAX][MAX*2], dist[MAX*MAX], pre[MAX*MAX];
vector<int> graph[MAX*MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	memset(map, -1, sizeof(map));
	for (int i=0; i<n; ++i) {
		for (int j=i%2; j<2*n-1; j+=2) {
			for (int k=0; k<2; ++k) {
				cin >> map[i][j+k];
				tile[i][j+k] = cur;
				if (i && map[i-1][j+k] == map[i][j+k]) {
					int prev = tile[i-1][j+k];
					graph[cur].push_back(prev);
					graph[prev].push_back(cur);
				}

			}
			if (j && map[i][j-1] == map[i][j]) {
				int prev = tile[i][j-1];
				graph[cur].push_back(prev);
				graph[prev].push_back(cur);
			}
			cur++;
		}
	}

	fill(pre, pre+MAX*MAX, -1);
	queue<int> que;
	dist[0] = 1;
	que.push(0);

	int ans = 0;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		ans = max(ans, cur);

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (!dist[next]) {
				pre[next] = cur;
				dist[next] = dist[cur] + 1;
				que.push(next);
			}
		}
	}

	stack<int> st;
	for (int i=ans; i!=-1; i=pre[i])
		st.push(i+1);

	cout << dist[ans] << '\n';
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}
