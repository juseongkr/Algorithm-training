#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001
typedef pair<int, int> pii;
int visit[MAX];

int main()
{
	priority_queue<pii, vector<pii>, greater<pii>> que;
	int n, k;

	cin >> n >> k;

	que.push({0, n});
	visit[n] = 1;
	while (!que.empty()) {
		int dep = que.top().first;
		int cur = que.top().second;
		que.pop();

		visit[cur] = 1;
		if (cur == k) {
			cout << dep << '\n';
			return 0;
		}

		if (cur + 1 <= MAX && !visit[cur+1])
			que.push({dep+1, cur+1});

		if (cur - 1 >= 0 && !visit[cur-1])
			que.push({dep+1, cur-1});

		if (cur * 2 <= MAX && !visit[cur*2])
			que.push({dep, cur*2});
	}

	return 0;
}
