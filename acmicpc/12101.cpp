#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<string> ans;

void dfs(int i, string s)
{
	if (i > n)
		return;

	if (i == n) {
		ans.push_back(s);
		return;
	}

	dfs(i + 1, s + "+1");
	dfs(i + 2, s + "+2");
	dfs(i + 3, s + "+3");
}

int main()
{
	cin >> n >> k;

	dfs(1, "1");
	dfs(2, "2");
	dfs(3, "3");

	sort(ans.begin(), ans.end());

	if (ans.size() < k)
		cout << "-1\n";
	else
		cout << ans[k-1] << '\n';

	return 0;
}
