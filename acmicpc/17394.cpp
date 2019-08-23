#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000001

int t, n, a, b;
bool check[MAX], prime[MAX];
bool visit[MAX];

int bfs()
{	
	fill(visit, visit+MAX, false);
	queue<pair<int, int>> que;
	visit[n] = 1;
	que.push({n, 0});

	while (!que.empty()) {
		int cur = que.front().first;
		int cost = que.front().second;
		que.pop();

		if (prime[cur] && a <= cur && cur <= b)
			return cost;
				
		if (cur > 0 && !visit[cur-1]) {
			visit[cur-1] = 1;
			que.push({cur-1, cost+1});
		}
		
		if (cur < MAX && !visit[cur+1]) {
			visit[cur+1] = 1;
			que.push({cur+1, cost+1});
		}

		if (cur != 0 && !visit[cur/2]) {
			visit[cur/2] = 1;
			que.push({cur/2, cost+1});
		}

		if (cur != 0 && !visit[cur/3]) {
			visit[cur/3] = 1;
			que.push({cur/3, cost+1});
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(check+2, check+MAX, true);
	for (int i=2; i<MAX; ++i) {
		if (check[i])
			prime[i] = true;
		for (int j=i; j<MAX; j+=i)
			check[j] = false;
	}

	cin >> t;
	while (t--) {
		cin >> n >> a >> b;

		bool flag = false;
		for (int i=a; i<=b; ++i)
			if (prime[i])
				flag = true;

		if (flag)
			cout << bfs() << '\n';
		else
			cout << "-1\n";
	}

	return 0;
}
