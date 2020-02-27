#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, t;
int a[MAX], b[MAX];
int tree[MAX*4];

void update(int i, int diff)
{
	while (i <= n) {
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
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		b[a[i]] = i+1;
	}

	int ans = 0;
	for (int i=0; i<n; ++i) {
		cin >> t;
		ans += sum(n) - sum(b[t]);
		update(b[t], 1);
	}

	if (ans % 2 == 0)
		cout << "Possible\n";
	else
		cout << "Impossible\n";

	return 0;
}
