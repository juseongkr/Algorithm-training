#include <iostream>
#include <vector>
using namespace std;

int n, m;
int visit[10];
vector<int> ans;

void dfs()
{
	if (ans.size() == m) {
		for (int i=0; i<ans.size(); ++i)
			cout << ans[i] << " ";
		cout << '\n';
		return;
	}

	for (int i=1; i<=n; ++i) {
		if (visit[i])
			continue;

		if (ans.size() == 0 || ans.back() < i) {
			visit[i] = 1;
			ans.push_back(i);
			dfs();
			ans.pop_back();
			visit[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;

	dfs();

	return 0;
}
