#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, k;
string s, c, ans;

int bfs()
{
	queue<pair<int, string>> que;
	set<string> visit;
	visit.insert(s);
	que.push({0, s});

	while (!que.empty()) {
		auto [cnt, str] = que.front();
		que.pop();

		if (str == ans)
			return cnt;

		for (int i=0; i<=str.length()-k; ++i) {
			string t = str;
			reverse(t.begin()+i, t.begin()+i+k);

			if (!visit.count(t)) {
				visit.insert(t);
				que.push({cnt+1, t});
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> c;
		s += c;
	}
	ans = s;
	sort(ans.begin(), ans.end());

	cout << bfs() << '\n';

	return 0;
}
