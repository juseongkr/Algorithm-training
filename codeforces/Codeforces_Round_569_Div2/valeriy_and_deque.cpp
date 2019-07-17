#include <iostream>
#include <deque>
using namespace std;
#define MAX 100001

int main()
{
	deque<long long> que;
	pair<long long, long long> ans[MAX];
	long long n, q, m, t;

	cin >> n >> q;
	for (int i=0; i<n; ++i) {
		cin >> t;
		que.push_back(t);
	}

	for (int i=0; i<n; ++i) {
		int a = que.front();
		que.pop_front();
		int b = que.front();
		que.pop_front();
		ans[i] = {a, b};
		if (a > b) {
			que.push_front(a);
			que.push_back(b);
		} else {
			que.push_front(b);
			que.push_back(a);
		}
	}

	while (q--) {
		cin >> m;
		if (m <= n) {
			cout << ans[m-1].first << " " << ans[m-1].second << '\n';
		} else {
			m -= (n+1);
			m %= (n-1);
			cout << que.front() << " " << que[m+1] << '\n';
		}
	}

	return 0;
}
