#include <iostream>
#include <vector>
using namespace std;

int n, m;
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
		ans.push_back(i);
		dfs();
		ans.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	dfs();

	return 0;
}
