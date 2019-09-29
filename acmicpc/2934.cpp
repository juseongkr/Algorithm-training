#include <iostream>
using namespace std;
#define MAX 100001

int n, x, y;
int tree[MAX];

void update(int i, int diff)
{
	while (i < MAX) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int sum(int i)
{
	int ret = 0;
	while (i) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		int a = sum(x);
		int b = sum(y);

		update(x, -a);
		update(x+1, a);

		update(y, -b);
		update(y+1, b);

		update(x+1, 1);
		update(y, -1);

		cout << a + b << '\n';
	}

	return 0;
}
