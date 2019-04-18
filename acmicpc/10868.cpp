#include <iostream>
using namespace std;

#define MAX_VAL 10e9+1;
long long num[100001], tree[4000002];
int n, m;

long long __make(int cur, int left, int right)
{
	if (left == right) {
		tree[cur] = num[right];
		return tree[cur];
	}

	int mid = (left+right)/2;
	long long left_tree = __make(2*cur, left, mid);
	long long right_tree = __make(2*cur+1, mid+1, right);
	tree[cur] = min(left_tree, right_tree);
	return tree[cur];
}

long long __min(int cur, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return MAX_VAL;

	if (start <= left && right <= end)
		return tree[cur];

	int mid = (left+right)/2;
	long long left_min = __min(2*cur, left, mid, start, end);
	long long right_min = __min(2*cur+1, mid+1, right, start, end);
	return min(left_min, right_min);
}

void make()
{
	__make(1, 1, n);
}

long long minimum(int a, int b)
{
	return __min(1, 1, n, a, b);
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
		printf("%lld\n", minimum(a, b));
	}

	return 0;
}
