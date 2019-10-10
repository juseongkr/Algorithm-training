#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 201

int n;
bool trans[MAX][MAX], visit[MAX];
int x[MAX], y[MAX], p[MAX];

int dist(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int bfs(int x)
{
	queue<int> que;
	visit[x] = true;
	que.push(x);

	int cnt = 1;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<n; ++i) {
			if (trans[cur][i] && !visit[i]) {
				visit[i] = true;
				que.push(i);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i] >> p[i];

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (dist(x[i], y[i], x[j], y[j]) <= p[i] * p[i])
				trans[i][j] = true;
	
	int ans = 1;
	for (int i=0; i<n; ++i) {
		memset(visit, false, sizeof(visit));
		ans = max(ans, bfs(i));
	}
	cout << ans << '\n';

	return 0;
}
