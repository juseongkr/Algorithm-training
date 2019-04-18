#include <iostream>
using namespace std;

long long num[100001], tree[400004];
int n, m;

long long __make(int cur, int left, int right)
{
	if (left == right) {
		tree[cur] = num[left];
		return tree[cur];
	}

	int mid = (left+right)/2;
	tree[cur] = __make(2*cur, left, mid) + __make(2*cur+1, mid+1, right);
	return tree[cur];
}

void __update(int cur, int left, int right, int idx, long long diff)
{
	if (idx < left || right < idx)
		return;

	tree[cur] += diff;
	if (left != right) {
		int mid = (left+right)/2;
		__update(2*cur, left, mid, idx, diff);
		__update(2*cur+1, mid+1, right, idx, diff);
	}
}

long long __sum(int cur, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return 0;

	if (start <= left && right <= end)
		return tree[cur];

	int mid = (left+right)/2;
	return __sum(2*cur, left, mid, start, end) + __sum(2*cur+1, mid+1, right, start, end);
}

void make()
{
	__make(1, 1, n);
}

void update(int a, long long b)
{
	__update(1, 1, n, a, b);
}

long long sum(int a, int b)
{
	return __sum(1, 1, n, a, b);
}

int main()
{
	long long x, y, a, b, ans;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		scanf("%lld", &num[i]);

	make();
	for (int i=0; i<m; ++i) {
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if (x > y)
			swap(x, y);
		printf("%lld\n", sum(x, y));
		update(a, b - num[a]);
		num[a] = b;
	}

	return 0;
}
