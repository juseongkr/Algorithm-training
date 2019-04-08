#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ret, li;
int n, m, t;

void dfs()
{
	if (ret.size() == m) {
		for (int i=0; i<ret.size(); ++i)
			printf("%d ", ret[i]);
		printf("\n");
		return;
	}

	for (int i=0; i<li.size(); ++i) {
		if (ret.empty()) {
			ret.push_back(li[i]);
			dfs();
			ret.pop_back();
		} else if (ret.back() <= li[i]) {
			ret.push_back(li[i]);
			dfs();
			ret.pop_back();
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		li.push_back(t);
	}

	sort(li.begin(), li.end());

	dfs();

	return 0;
}
