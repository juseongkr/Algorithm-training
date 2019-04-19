#include <iostream>
using namespace std;

long long num[2000001], tree[4000002];
long long a, b, c;
int n, m;

long long __make(int cur, int left, int right)
{
	if (left == right) {
		tree[cur] = num[right];
		return tree[cur];
	}

	int mid = (left + right)/2;
	tree[cur] = __make(2*cur, left, mid) + \
		    __make(2*cur+1, mid+1, right);
	return tree[cur];
}

void __update(int cur, int left, int right, int idx, long long diff)
{
	if (idx < left || right < idx)
		return;

	tree[cur] += diff;
	if (left != right) {
		int mid = (left + right)/2;
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

	int mid = (left + right)/2;
	return __sum(2*cur, left, mid, start, end) + \
		__sum(2*cur+1, mid+1, right, start, end);
}

void make()
{
	__make(1, 1, n);
}

void update(int i, long long d)
{
	__update(1, 1, n, i, d);
}

long long sum(int s, int e)
{
	return __sum(1, 1, n, s, e);
}

int main()
{
	scanf("%d %d", &n, &m);

	make();
	for (int i=0; i<m; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			long long diff = c - num[b];
			update(b, diff);
			num[b] = c;
		} else {
			if (b > c)
				swap(b, c);
			long long ans = sum(b, c);
			printf("%lld\n", ans);
		}
	}

	return 0;
}
