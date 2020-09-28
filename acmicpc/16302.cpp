#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 1001
typedef tuple<int, int, int> tp;

int calc(string a, string b)
{
	int cnt = 0;
	for (int i=0; i<a.length(); ++i)
		if (a[i] != b[i])
			cnt++;

	return cnt;
}

class UnionFind {
public:
	vector<int> p;
	UnionFind(int n) { p.resize(n+1, -1); }
	int find(int x)
	{
		if (p[x] < 0)
			return x;
		return p[x] = find(p[x]);
	}

	bool uni(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (p[x] < p[y])
			swap(x, y);
		p[y] += p[x];
		p[x] = y;
		return true;
	}

	int getSize(int x)
	{
		return -p[find(x)];
	}
};

int n, k;
string s[MAX];
vector<tp> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			int cost = calc(s[i], s[j]);
			vec.push_back({cost, i, j});
		}
	}

	sort(vec.begin(), vec.end());

	UnionFind uf(n);
	int cnt = 0, sum = 0;
	vector<pair<int, int>> ans;
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (uf.uni(x, y)) {
			sum += z;
			ans.push_back({x, y});
			if (++cnt == n-1)
				break;
		}
	}

	sort(ans.begin(), ans.end());

	cout << sum << '\n';
	for (int i=0; i<ans.size(); ++i)
		cout << ans[i].first << " " << ans[i].second << '\n';


	return 0;
}
