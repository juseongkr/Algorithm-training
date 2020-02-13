#include <iostream>
#include <set>
using namespace std;

int t;
string s, ans;
set<int> graph[26];
bool visit[26];

void dfs(int cur)
{
	ans += cur+'a';
	visit[cur] = 1;
	for (auto next : graph[cur])
		if (!visit[next])
			dfs(next);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		ans = "";
		fill(visit, visit+26, 0);
		for (int i=0; i<26; ++i)
			graph[i].clear();

		cin >> s;
		for (int i=0; i<s.length()-1; ++i) {
			int x = s[i]-'a';
			int y = s[i+1]-'a';
			graph[x].insert(y);
			graph[y].insert(x);
		}

		int cnt = 0;
		bool flag = false;
		for (int i=0; i<26; ++i) {
			if (graph[i].size() > 2) {
				flag = true;
				break;
			}

			if (graph[i].size() == 0)  {
				ans += i+'a';
			}
		}

		if (flag) {
			cout << "NO\n";
			continue;
		}

		for (int i=0; i<26; ++i)
			if (!visit[i] && graph[i].size() == 1)
				dfs(i);

		if (ans.length() == 26)
			cout << "YES\n" << ans << '\n';
		else
			cout << "NO\n";
	}

	return 0;
}
