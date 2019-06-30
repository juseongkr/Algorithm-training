#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 300001

bool cmp(int a, int b) { return a > b; }

int main()
{
	int num[MAX];
	int n, max_val = 0;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n, cmp);

	int ans = 0;
	for (int i=0; i<n; ++i) {
		if (num[i] + n >= max_val)
			ans++;
		max_val = max(max_val, num[i] + i + 1);
	}
	cout << ans << '\n';

	return 0;
}
