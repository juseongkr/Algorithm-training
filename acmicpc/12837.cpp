#include <iostream>
using namespace std;

long long tree[4000004];
int n, m;

void __update(int cur, int left, int right, int idx, long long val)
{
	if (idx < left || right < idx)
		return;

	tree[cur] += val;
	if (left != right) {
		int mid = (left+right)/2;
		__update(2*cur, left, mid, idx, val);
		__update(2*cur+1, mid+1, right, idx, val);
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

void update(int a, int b)
{
	__update(1, 1, n, a, b);
}

long long sum(int a, int b)
{
	return __sum(1, 1, n, a, b);
}

int main()
{
	long long a, b, c;

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			update(b, c);
		} else {
			printf("%lld\n", sum(b, c));
		}
	}

	return 0;
}
