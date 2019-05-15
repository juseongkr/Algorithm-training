#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001
int visit[MAX], history[MAX];
vector<int> ans;

int main()
{
	queue<pair<int, int>> que;
	int n, k;

	cin >> n >> k;

	que.push({n, 0});
	while (!que.empty()) {
		int cur = que.front().first;
		int dep = que.front().second;
		que.pop();

		if (cur == k) {
			int i = cur;
			while (i != n) {
				ans.push_back(i);
				i = history[i];
			}
			cout << dep << '\n';
			break;
		}

		if (cur + 1 <= MAX && !visit[cur+1]) {
			que.push({cur+1, dep+1});
			visit[cur+1] = 1;
			history[cur+1] = cur;
		}

		if (cur - 1 >= 0 && !visit[cur-1]) {
			que.push({cur-1, dep+1});
			visit[cur-1] = 1;
			history[cur-1] = cur;
		}

		if (cur * 2 <= MAX && !visit[cur*2]) {
			que.push({cur*2, dep+1});
			visit[cur*2] = 1;
			history[cur*2] = cur;
		}
	}

	cout << n << " ";
	for (int i=ans.size()-1; i>=0; i--)
		cout << ans[i] << " ";

	return 0;
}
