#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
#define MAX 1001

int n;
bool visit[MAX];
int x[MAX], y[MAX];

int dist(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool bfs(int cost)
{
	queue<int> que;
	visit[0] = true;
	que.push(0);

	int cnt = 1;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<n; ++i) {
			if (!visit[i] && dist(x[cur], y[cur], x[i], y[i]) <= cost) {
				visit[i] = true;
				que.push(i);
				cnt++;
			}
		}
	}
	return (cnt == n);
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];

	int l = 0, r = INT_MAX;
	int ans = INT_MAX;
	while (l <= r) {
		memset(visit, false, sizeof(visit));
		int mid = (l+r)/2;
		if (bfs(mid)) {
			r = mid-1;
			ans = min(ans, mid);
		} else {
			l = mid+1;
		}
	}
	cout << ans << '\n';

	return 0;
}
