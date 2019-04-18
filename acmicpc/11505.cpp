#include <iostream>
using namespace std;

#define MOD 1000000007
int n, m, k;
long long a, b, c;
long long num[1000002], tree[4000002];

long long __make(int cur, int left, int right)
{
	if (left == right) {
		tree[cur] = num[left];
		return tree[cur];
	}

	int mid = (left+right)/2;
	tree[cur] = __make(2*cur, left, mid) % MOD * \
		    __make(2*cur+1, mid+1, right) % MOD;
	return tree[cur];
}


long long __mul(int cur, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return 1;

	if (start <= left && right <= end)
		return tree[cur];

	int mid = (left+right)/2;
	return __mul(2*cur, left, mid, start, end) % MOD * \
		__mul(2*cur+1, mid+1, right, start, end) % MOD;
}

long long __update(int cur, int left, int right, int idx, long long val)
{
	if (idx < left || right < idx)
		return tree[cur];

	if (left == right) {
		tree[cur] = val;
		return tree[cur];
	}

	int mid = (left+right)/2;
	tree[cur] = __update(2*cur, left, mid, idx, val) % MOD * \
		    __update(2*cur+1, mid+1, right, idx, val) % MOD;
	return tree[cur];
}

void make()
{
	__make(1, 1, n);
}

long long mul(int a, int b)
{
	return __mul(1, 1, n, a, b);
}

long long update(int a, int b)
{
	return __update(1, 1, n, a, b);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i=1; i<=n; ++i)
		scanf("%lld", &num[i]);

	make();
	for (int i=0; i<m+k; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			update(b, c);
			num[b] = c;
		} else {
			printf("%lld\n", mul(b, c));
		}
	}

	return 0;
}
