#include <iostream>
#include <queue>
#include <set>
#include <tuple>
using namespace std;
#define MAX 100001
typedef tuple<int, int, int> tp;

int a, b, c, d;
queue<tp> que;
set<int> visit[MAX];

int main()
{
	cin >> a >> b >> c >> d;

	que.push({0, 0, 0});
	visit[0].insert(0);

	while (!que.empty()) {
		auto [x, y, dep] = que.front();
		que.pop();

		if (x == c && y == d) {
			cout << dep << '\n';
			return 0;
		}

		if (!visit[a].count(y)) {
			visit[a].insert(y);
			que.push({a, y, dep+1});
		}

		if (!visit[x].count(b)) {
			visit[x].insert(b);
			que.push({x, b, dep+1});
		}

		if (!visit[0].count(y)) {
			visit[0].insert(y);
			que.push({0, y, dep+1});
		}

		if (!visit[x].count(0)) {
			visit[x].insert(0);
			que.push({x, 0, dep+1});
		}

		int rest = min(b - y, x);
		int l = x - rest, r = y + rest;
		if (!visit[l].count(r)) {
			visit[l].insert(r);
			que.push({l, r, dep+1});
		}

		rest = min(a - x, y);
		l = x + rest, r = y - rest;
		if (!visit[l].count(r)) {
			visit[l].insert(r);
			que.push({l, r, dep+1});
		}
	}
	cout << "-1\n";

	return 0;
}
