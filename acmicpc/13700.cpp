#include <iostream>
#include <queue>
#include <set>
using namespace std;
#define MAX 100001

bool visit[MAX];

int main()
{
	set<int> police;
	int n, s, d, f, b, k, p;

	cin >> n >> s >> d >> f >> b >> k;
	for (int i=0; i<k; ++i) {
		cin >> p;
		police.insert(p);
	}

	queue<pair<int, int>> que;
	que.push({s, 0});
	visit[s] = true;

	while (!que.empty()) {
		auto [cur, cnt] = que.front();
		que.pop();

		if (cur == d) {
			cout << cnt << '\n';
			return 0;
		}

		int next = cur + f;
		if (next <= n && !visit[next] && !police.count(next)) {
			visit[next] = true;
			que.push({next, cnt+1});
		}

		next = cur - b;
		if (next >= 0 && !visit[next] && !police.count(next)) {
			visit[next] = true;
			que.push({next, cnt+1});
		}
	}
	cout << "BUG FOUND\n";

	return 0;
}
