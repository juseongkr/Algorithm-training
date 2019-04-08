#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ret, li;
int visit[10];
int n, m, t;

void dfs()
{
	int depth[10001] = {0, };

	if (ret.size() == m) {
		for (int i=0; i<ret.size(); ++i)
			printf("%d ", ret[i]);
		printf("\n");
		return;
	}
	
	for (int i=0; i<n; ++i) {
		if (visit[i] == 0 && depth[li[i]] == 0) {
			visit[i] = 1;
			depth[li[i]] = 1;
			ret.push_back(li[i]);
			dfs();
			ret.pop_back();
			visit[i] = 0;
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
