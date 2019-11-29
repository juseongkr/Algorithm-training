#include <iostream>
using namespace std;
#define MAX 2001

int n, ans;
int num[MAX];
int d1[MAX], d2[MAX];

int f(int x)
{
	if (x == n)
		return 0;

	if (d1[x] != -1)
		return d1[x];

	d1[x] = 0;
	for (int i=x+1; i<n; ++i)
		if (num[x] < num[i])
			d1[x] = max(d1[x], f(i)+1);

	return d1[x];
}

int b(int x)
{
	if (x == n)
		return 0;

	if (d2[x] != -1)
		return d2[x];

	d2[x] = 0;
	for (int i=x+1; i<n; ++i)
		if (num[x] > num[i])
			d2[x] = max(d2[x], b(i)+1);

	return d2[x];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	fill(d1, d1+MAX, -1);
	fill(d2, d2+MAX, -1);
	for (int i=0; i<n; ++i)
		ans = max(ans, f(i) + b(i) + 1);

	cout << ans << '\n';

	return 0;
}
