#include <iostream>
using namespace std;
#define MAX 2001
#define DEP 16

int parent[MAX][DEP], depth[MAX], node[MAX*2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	string s;

	cin >> n >> s;
	int cur = 1, idx = 0;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '1') {
			node[i+1] = cur;
			cur = parent[cur][0];
		} else {
			parent[++idx][0] = cur;
			depth[idx] = depth[cur] + 1;
			node[i+1] = idx;
			cur = idx;
		}
	}
	for (int j=1; j<DEP; ++j)
		for (int i=1; i<=s.length()/2; ++i)
			parent[i][j] = parent[parent[i][j-1]][j-1];

	cin >> x >> y;
	int X = x, Y = y;
	x = node[x];
	y = node[y];
	if (depth[x] > depth[y])
		swap(x, y);

	for (int i=DEP-1; i>=0; i--)
		if (depth[x] <= depth[parent[y][i]])
			y = parent[y][i];

	int lca = x;
	if (x != y) {
		for (int i=DEP-1; i>=0; i--) {
			if (parent[x][i] != parent[y][i]) {
				x = parent[x][i];
				y = parent[y][i];
			}
		}
		lca = parent[x][0];
	}

	for (int i=0; i<s.length(); ++i) {
		if (node[i+1] == lca) {
			if (s[i] == '1')
				Y = i+1;
			else
				X = i+1;
		}
	}
	cout << X << " " <<  Y << '\n';

	return 0;
}
