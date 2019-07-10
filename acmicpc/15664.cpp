#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_LEN 9
#define MAX_VAL 10001

int n, m;
int num[MAX_LEN], visit[MAX_VAL];
vector<int> ans;

void dfs()
{
	int duple[MAX_VAL] = {0, };

	if (ans.size() == m) {
		for (int i=0; i<ans.size(); ++i)
			cout << ans[i] << " ";
		cout << '\n';
		return;
	}

	for (int i=0; i<n; ++i) {
		if (visit[i] || duple[num[i]])
			continue;

		if (ans.size() == 0 || ans.back() <= num[i]) {
			visit[i] = 1;
			duple[num[i]] = 1;
			ans.push_back(num[i]);
			dfs();
			ans.pop_back();
			visit[i] = 0;
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
