#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_LEN 9

int n, m;
int num[MAX_LEN];
vector<int> ans;

void dfs()
{
	if (ans.size() == m) {
		for (int i=0; i<ans.size(); ++i)
			cout << ans[i] << " ";
		cout << '\n';
		return;
	}

	for (int i=0; i<n; ++i) {
		if (ans.size() == 0 || ans.back() <= num[i]) {
			ans.push_back(num[i]);
			dfs();
			ans.pop_back();
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	dfs();

	return 0;
}
