#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAX 16

int n, l, r, x, ans;
int num[MAX], visit[MAX];
vector<int> vec;

void solve(int cur, int cnt, int val)
{
	if (cnt >= 2) {
		int sum = 0, max_val = 0, min_val = INT_MAX;
		for (int i=0; i<vec.size(); ++i) {
			sum += num[vec[i]];
			min_val = min(min_val, num[vec[i]]);
			max_val = max(max_val, num[vec[i]]);
		}

		if (l <= sum && sum <= r && max_val - min_val >= x)
			ans++;
	}

	for (int i=cur; i<n; ++i) {
		if (visit[i])
			continue;

		if (val + num[i] <= r) {
			visit[i] = 1;
			vec.push_back(i);
			solve(i, cnt+1, val + num[i]);
			vec.pop_back();
			visit[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> l >> r >> x;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	solve(0, 0, 0);

	cout << ans << '\n';

	return 0;
}
