#include <iostream>
using namespace std;
#define MAX 100001

char op;
long long n, m, a, b, t;
long long num[MAX], tree[4*MAX];

long long __make(int cur, int left, int right)
{
	if (left == right) {
		tree[cur] = num[left];
		return tree[cur];
	}

	int mid = (left+right)/2;
	tree[cur] = __make(2*cur, left, mid) * \
		    __make(2*cur+1, mid+1, right);
	return tree[cur];
}

long long __mul(int cur, int left, int right, int start, int end)
{
	if (end < left || right < start)
		return 1;

	if (start <= left && right <= end)
		return tree[cur];

	int mid = (left+right)/2;
	return __mul(2*cur, left, mid, start, end) * \
		__mul(2*cur+1, mid+1, right, start, end);
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
	tree[cur] = __update(2*cur, left, mid, idx, val) * \
		    __update(2*cur+1, mid+1, right, idx, val);
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> n) {
		cin >> m;
		for (int i=1; i<=n; ++i) {
			cin >> t;
			if (t > 0)
				num[i] = 1;
			else if (t < 0)
				num[i] = -1;
			else
				num[i] = 0;
		}

		make();
		for (int i=0; i<m; ++i) {
			cin >> op >> a >> b;
			if (op == 'C') {
				if (b > 0)
					update(a, 1);
				else if (b < 0)
					update(a, -1);
				else
					update(a, 0);
			} else {
				long long ans = mul(a, b);
				if (ans > 0)
					cout << "+";
				else if (ans < 0)
					cout << "-";
				else
					cout << "0";
			}
		}
		cout << '\n';
	}

	return 0;
}
