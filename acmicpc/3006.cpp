#include <iostream>
using namespace std;
#define MAX 100001

int n;
long long tree[MAX];
int num[MAX], pos[MAX];

void update(int i, long long diff)
{
	while (i <= MAX) {
		tree[i] += diff;
		i += (i & -i);
	}
}

long long sum(int i)
{
	long long ret = 0;
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
	for (int i=1; i<=n; ++i) {
		cin >> num[i];
		pos[num[i]] = i;
		update(i, 1);
	}

	int l = 1, r = n;
	for (int i=0; i<n; ++i) {
		if (i % 2 == 0) {
			update(pos[l], -1);
			cout << sum(pos[l]) << '\n';
			l++;
		} else {
			update(pos[r], -1);
			cout << sum(n) - sum(pos[r]) << '\n';
			r--;
		}
	}
	return 0;
}
