#include <iostream>
#include <queue>
using namespace std;

long long a, b;

int main()
{
	cin >> a >> b;
	queue<pair<long long, long long>> que;
	que.push({a, 1});

	while (!que.empty()) {
		auto [cur, cnt] = que.front();
		que.pop();

		if (cur == b) {
			cout << cnt << '\n';
			return 0;
		}

		if (cur*2 <= b)
			que.push({cur*2, cnt+1});

		if (cur*10+1 <= b)
			que.push({cur*10+1, cnt+1});
	}
	cout << "-1\n";

	return 0;
}
