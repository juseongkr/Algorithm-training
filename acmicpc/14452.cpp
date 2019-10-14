#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001
typedef pair<int, int> pii;

int n, t;
int cow[MAX];

bool check(int m)
{
	priority_queue<pii, vector<pii>, greater<pii>> que;
	int ret = 0;

	for (int i=0; i<min(m, n); ++i) {
		que.push({cow[i], i});
		ret = max(ret, cow[i]);
	}

	for (int i=m; i<n; ++i) {
		auto cur = que.top();
		cur.first += cow[i];
		que.pop();
		ret = max(ret, cur.first);
		que.push(cur);
	}

	if (ret <= t)
		return true;
	return false;
}

int main()
{
	cin >> n >> t;
	for (int i=0; i<n; ++i)
		cin >> cow[i];

	int l = 0, r = n;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << l << '\n';

	return 0;
}
