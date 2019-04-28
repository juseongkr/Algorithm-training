#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int t, n, m, d;

	scanf("%d", &t);
	while (t--) {
		int cnt = 0;
		queue<pair<int, int>> que;
		priority_queue<int> heap;

		scanf("%d %d", &n, &m);
		for (int j=0; j<n; ++j) {
			scanf("%d", &d);
			que.push({j, d});
			heap.push(d);
		}

		while (!que.empty()) {
			auto p = que.front();
			que.pop();
			if (p.second == heap.top()) {
				heap.pop();
				cnt++;
				if (p.first == m) {
					printf("%d\n", cnt);
					break;
				}
			} else {
				que.push({p.first, p.second});
			}
		}
	}

	return 0;
}
