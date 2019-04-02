#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> tree[100001];
int parent[100001];
int n, a, b;

void dfs(int s)
{
	for (int i=0; i<tree[s].size(); ++i) {
		if (parent[tree[s][i]] == -1) {
			parent[tree[s][i]] = s;
			dfs(tree[s][i]);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n-1; ++i) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	memset(parent, -1, sizeof(parent));

	dfs(1);

	for (int i=2; i<=n; ++i)
		printf("%d\n", parent[i]);

	return 0;
}
