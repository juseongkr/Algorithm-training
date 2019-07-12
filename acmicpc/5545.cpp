#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101

bool cmp(int a, int b) { return a > b; }

int main()
{
	int t[MAX];
	int n, a, b, c;

	cin >> n >> a >> b >> c;
	for (int i=0; i<n; ++i)
		cin >> t[i];

	sort(t, t+n, cmp);

	int ans = c / a;
	for (int i=0; i<n; ++i) {
		int sum = t[i];
		for (int j=0; j<i; ++j)
			sum += t[j];

		int cal = (sum + c) / (a + (b * (i+1)));
		ans = max(ans, cal);
	}
	cout << ans << '\n';

	return 0;
}
