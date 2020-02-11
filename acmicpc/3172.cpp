#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100001

int n;
int tree[MAX*4];
vector<string> vec;
vector<pair<string, int>> rev;
string s;

void update(int i, int diff)
{
	while (i <= n) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int sum(int i)
{
	int ret = 0;
	while (i) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int sum(int l, int r) { return sum(r) - sum(l-1); }

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		vec.push_back(s);
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<n; ++i) {
		reverse(vec[i].begin(), vec[i].end());
		rev.push_back({vec[i], i+1});
	}

	sort(rev.begin(), rev.end());

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		int idx = rev[i].second;
		ans += sum(idx, n);
		update(idx, 1);
	}
	cout << ans << '\n';

	return 0;
}
