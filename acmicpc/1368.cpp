#include <iostream>
#include <queue>
using namespace std;
#define MAX 301

int n, x, ans;
bool visit[MAX];
int water[MAX][MAX];

int main()
{
	priority_queue<pair<int, int>> que;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x;
		que.push({-x, i});
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> water[i][j];

	while (!que.empty()) {
		auto [c, k] = que.top();
		que.pop();

		if (!visit[k]) {
			visit[k] = 1;
			ans -= c;
			for (int i=0; i<n; ++i)
				que.push({-water[k][i], i});
		}
	}
	cout << ans << '\n';

	return 0;
}
