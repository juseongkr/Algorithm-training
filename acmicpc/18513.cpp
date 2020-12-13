#include <iostream>
#include <queue>
#include <set>
using namespace std;
#define MAX 100001
const int dx[2] = {-1, 1};

int n, k, p;
queue<pair<int, int>> que;
set<int> visit;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> p;
		que.push({p, p});
		visit.insert(p);
	}

	long long ans = 0;
	while (!que.empty()) {
		auto [cur, root] = que.front();
		que.pop();

		for (int i=0; i<2; ++i) {
			int next = cur + dx[i];

			if (visit.count(next))
				continue;

			ans += abs(root - next);
			if (--k == 0) {
				cout << ans << '\n';
				exit(0);
			}

			visit.insert(next);
			que.push({next, root});
		}
	}

	return 0;
}
