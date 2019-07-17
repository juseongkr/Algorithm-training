#include <iostream>
#include <queue>
using namespace std;
#define MAX 10000

bool check[MAX], prime[MAX];
int visit[MAX];

int main()
{
	int t, n, m;

	fill(check+2, check+MAX, true);
	for (int i=2; i<=MAX; ++i) {
		if (check[i])
			prime[i] = true;
		for (int j=i; j<=MAX; j+=i)
			check[j] = false;
	}

	cin >> t;
	while (t--) {
		cin >> n >> m;
		fill(visit, visit+MAX, 0);
		queue<int> que;
		visit[n] = 1;
		que.push(n);

		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			for (int i=0; i<4; ++i) {
				for (int j=0; j<10; ++j) {
					int next = -1;
					if (i != 0 || j != 0) {
						string s = to_string(cur);
						s[i] = j+'0';
						next = stoi(s.c_str());
					}
					if (next == -1)
						continue;

					if (prime[next] && !visit[next]) {
						visit[next] = visit[cur] + 1;
						que.push(next);
					}
				}
			}
		}
		cout << visit[m] - 1 << '\n';
	}

	return 0;
}
