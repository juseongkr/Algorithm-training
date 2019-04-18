#include <iostream>
using namespace std;

#define MAX_VAL 10e9+1;
long long num[100001], min_tree[4000002], max_tree[4000002];
int n, m;

long long __make_min(int cur, int left, int right)
{
	if (left == right) {
		min_tree[cur] = num[right];
		return min_tree[cur];
	}

	int mid = (left+right)/2;
	long long left_tree = __make_min(2*cur, left, mid);
	long long right_tree = __make_min(2*cur+1, mid+1, right);
	min_tree[cur] = min(left_tree, right_tree);
	return min_tree[cur];
}

long long __make_max(int cur, int left, int right)
{
	if (left == right) {
		max_tree[cur] = num[right];
		return max_tree[cur];
	}

	int mid = (left+right)/2;
	long long left_tree = __make_max(2*cur, left, mid);
	long long right_tree = __make_max(2*cur+1, mid+1, right);
	max_tree[cur] = max(left_tree, right_tree);
	return max_tree[cur];
}

long long __min(int cur, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return MAX_VAL;

	if (start <= left && right <= end)
		return min_tree[cur];

	int mid = (left+right)/2;
	long long left_min = __min(2*cur, left, mid, start, end);
	long long right_min = __min(2*cur+1, mid+1, right, start, end);
	return min(left_min, right_min);
}

long long __max(int cur, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return 0;

	if (start <= left && right <= end)
		return max_tree[cur];

	int mid = (left+right)/2;
	long long left_min = __max(2*cur, left, mid, start, end);
	long long right_min = __max(2*cur+1, mid+1, right, start, end);
	return max(left_min, right_min);
}

void make()
{
	__make_min(1, 1, n);
	__make_max(1, 1, n);
}

long long minimum(int a, int b)
{
	return __min(1, 1, n, a, b);
}

long long maximum(int a, int b)
{
	return __max(1, 1, n, a, b);
}

int main()
{
	int a, b;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		scanf("%lld", &num[i]);

	make();
	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		printf("%lld %lld\n", minimum(a, b), maximum(a, b));
	}

	return 0;
}
