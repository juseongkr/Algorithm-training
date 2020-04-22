#include <iostream>
#include <queue>
using namespace std;
#define MAX 11

int n, k, p;
int a[MAX];
bool visit[360];

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	queue<int> que;
	visit[0] = 1;
	que.push(0);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		int next = 360-cur;
		if (next && !visit[next]) {
			visit[next] = 1;
			que.push(next);
		}

		for (int i=0; i<n; ++i) {
			int next = (cur+a[i]) % 360;
			if (next < 360 && !visit[next]) {
				visit[next] = 1;
				que.push(next);
			}
		}
	}

	for (int i=0; i<k; ++i) {
		cin >> p;
		if (visit[p])
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
