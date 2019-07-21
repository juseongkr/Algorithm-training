#include <iostream>
#include <queue>
using namespace std;
#define MAX 10000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int visit[MAX];
	string ans;
	int t, a, b;

	cin >> t;
	while (t--) {
		fill(visit, visit+MAX, 0);
		cin >> a >> b;

		queue<pair<int, string>> que;
		que.push({a, ""});
		visit[a] = 1;

		while (!que.empty()) {
			int cur = que.front().first;
			string s = que.front().second;
			que.pop();

			if (cur == b) {
				cout << s << '\n';
				break;
			}

			int next = (cur*2) % MAX;
			if (!visit[next]) {
				visit[next] = 1;
				que.push({next, s + "D"});
			}

			if (cur-1 < 0)
				next = 9999;
			else
				next = cur-1;
			if (!visit[next]) {
				visit[next] = 1;
				que.push({next, s + "S"});
			}

			next = (cur / 1000) + (cur % 1000) * 10;
			if (!visit[next]) {
				visit[next] = 1;
				que.push({next, s + "L"});
			}

			next = (cur / 10) + (cur % 10) * 1000;
			if (!visit[next]) {
				visit[next] = 1;
				que.push({next, s + "R"});
			}
		}
	}

	return 0;
}
