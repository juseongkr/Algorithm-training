#include <iostream>
using namespace std;
#define MAX 101

int p[MAX];

int find(int n)
{
	if (p[n] < 0)
		return n;
	return p[n] = find(p[n]);
}

void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y) {
		p[x] += p[y];
		p[y] = x;
	}
}

int main()
{
	int n, k, a, b;

	cin >> k >> n;
	fill(p, p+MAX, -1);
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		uni(a, b);
	}

	cout << abs(p[find(1)]) - 1 << '\n';

	return 0;
}
