#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> que;
	vector<int> vec[32001];
	int in[100001] = {0, };
	int n, m, a, b;

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		in[b]++;
	}

	for (int i=1; i<=n; ++i)
		if (in[i] == 0)
			que.push(i);

	while (!que.empty()) {
		int t = que.top();
		que.pop();
		printf("%d ", t);

		for (int i=0; i<vec[t].size(); ++i) {
			int next = vec[t][i];
			in[next]--;
			if (in[next] == 0)
				que.push(next);
		}
	}

	return 0;
}
