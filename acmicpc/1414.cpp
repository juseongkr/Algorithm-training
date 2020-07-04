#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 101
typedef tuple<int, int, int> tp;

int n, total;
vector<tp> vec;
string s;

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
};

int dist(char s)
{
	if (s == '0')
		return 0;
	return s <= 'Z' ? s-'A'+27 : s-'a'+1;
}

int main()
{
	cin >> n;
	UnionFind u(n);
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<n; ++j) {
			int x = dist(s[j]);
			if (x) {
				total += x;
				vec.push_back({x, i, j});
			}
		}
	}

	sort(vec.begin(), vec.end());

	int ans = 0, cnt = 0;
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (u.uni(x, y)) {
			ans += z;
			cnt++;
		}
	}

	if (cnt == n-1)
		cout << total - ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
