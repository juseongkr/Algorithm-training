#include <iostream>
using namespace std;

#define MAX 500005
int root[MAX];
int n, m, k, a, b;

int find(int n)
{
        if(root[n] < 0)
		return n;
        return root[n] = find(root[n]);
}

void uni(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if (x != y) {
		root[x] += root[y];
		root[y] = x;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	fill(root, root+n+1, -1);

	for (int i=0; i<m; ++i) {
		cin >> k;
		if (k == 0)
			continue;
		cin >> a;
		while (--k) {
			cin >> b;
			if (find(a) != find(b))
				uni(a, b);
		}
	}

	for (int i=1; i<=n; ++i)
		cout << abs(root[find(i)]) << " ";
	cout << '\n';

	return 0;
}
