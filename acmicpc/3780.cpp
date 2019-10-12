#include <iostream>
using namespace std;
#define MAX 20001
#define MOD 1000

int p[MAX], line[MAX];

int find(int x)
{
	if (p[x] == 0)
		return x;
	int t = find(p[x]);
	line[x] += line[p[x]];
	p[x] = t;
	return t;
}

void uni(int x, int y)
{
	line[x] = abs(y-x) % MOD;
	p[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, n, u, v;
	char op;

	cin >> t;
	while (t--) {
		fill(p, p+MAX, 0);
		fill(line, line+MAX, 0);
		cin >> n;
		while (1) {
			cin >> op;
			if (op == 'O') {
				break;
			} else if (op == 'E') {
				cin >> u;
				find(u);
				cout << line[u] << '\n';
			} else {
				cin >> u >> v;
				uni(u, v);
			}
		}
	}

	return 0;
}
