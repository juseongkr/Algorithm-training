#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	queue<int> que;
	vector<int> vec[10001], ret;
	int in[10001] = {0, };
	int n, m, a, b, c;

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		for (int j=1; j<a; ++j) {
			scanf("%d", &c);
			in[c]++;
			vec[b].push_back(c);
			b = c;
		}
	}

	for (int i=1; i<=n; ++i)
		if (in[i] == 0)
			que.push(i);

	while (!que.empty()) {
		int t = que.front();
		que.pop();
		ret.push_back(t);

		for (int j=0; j<vec[t].size(); ++j) {
			int next = vec[t][j];
			in[next]--;
			if (in[next] == 0)
				que.push(next);
		}
	}

	if (ret.size() != n) {
		printf("0\n");
	} else {
		for (int i=0; i<ret.size(); ++i)
			printf("%d ", ret[i]);
	}

	return 0;
}
