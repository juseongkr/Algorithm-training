#include <iostream>
#include <queue>
using namespace std;
#define MAX 200002

int n;
int a[MAX], in[MAX], visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	n *= 2;
	for (int i=1; i<=n; ++i) {
		cin >> a[i];
		in[a[i]]++;
	}

	queue<int> que;

	for (int i=1; i<=n; ++i)
		if (!in[i])
			que.push(i);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		cout << cur << ' ';;

		visit[cur] = 1;
		if (!visit[a[cur]]) {
			visit[a[cur]] = 1;
			if (--in[a[a[cur]]] == 0)
				que.push(a[a[cur]]);
		}
	}

	for (int i=1; i<=n/2; ++i)
		if (!visit[i])
			cout << i << " ";

	return 0;
}
