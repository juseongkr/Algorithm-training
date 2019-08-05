#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 300003

int num[MAX], p[MAX];

bool cmp(int a, int b) { return a > b; }

int main()
{
	int n, k;

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n-1; ++i)
		p[i] = num[i+1] - num[i];

	sort(p, p+n-1, cmp);

	int ans = num[n-1] - num[0];
	for (int i=0; i<k-1; ++i)
		ans -= p[i];

	cout << ans << '\n';

	return 0;
}
